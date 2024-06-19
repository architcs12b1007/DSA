#include <iostream>
#include <vector>

using namespace std;

// price[i] of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete at most two transactions.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6 {3-0=3; 4-1=3}

// Approach:{} {Buy,Sell} {Buy,Sell,Buy,Sell}  [only thse 3 cases are possible] so put limit=2;

int solve(vector<int> &prices, int index, int buy, int limit)
{
    if (index == prices.size() || limit == 0)
        return 0;

    int profit = 0;

    if (buy)
    {
        int buyIncluded = -prices[index] + solve(prices, index + 1, 0, limit);
        int buySkip = solve(prices, index + 1, 1, limit);
        profit = max(buyIncluded, buySkip);
    }
    else
    {
        int sellIncluded = prices[index] + solve(prices, index + 1, 1, limit - 1);
        int sellSkip = solve(prices, index + 1, 0, limit);
        profit = max(sellIncluded, sellSkip);
    }

    return profit;
}

int maxProfit(vector<int> &prices)
{
    int index = 0;
    int limit = 2;
    int buy = 1;

    return solve(prices, index, buy, limit);
}

// Add memoization: Time Complexity:O(N) Space Complexity:O(N)

int solve1(vector<int> &prices, int index, int buy, int limit, vector<vector<vector<int>>> &dp)
{
    if (index == prices.size() || limit == 0)
        return 0;

    if (dp[index][buy][limit] != -1)
    {
        return dp[index][buy][limit];
    }

    int profit = 0;

    if (buy)
    {
        int buyIncluded = -prices[index] + solve1(prices, index + 1, 0, limit, dp);
        int buySkip = solve1(prices, index + 1, 1, limit, dp);
        profit = max(buyIncluded, buySkip);
    }
    else
    {
        int sellIncluded = prices[index] + solve1(prices, index + 1, 1, limit - 1, dp);
        int sellSkip = solve1(prices, index + 1, 0, limit, dp);
        profit = max(sellIncluded, sellSkip);
    }

    return dp[index][buy][limit] = profit;
}

int maxProfit1(vector<int> &prices)
{
    int index = 0;
    int limit = 2;
    int buy = 1;
    int n = prices.size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    return solve1(prices, index, buy, limit, dp);
}

// Add Tabulation: Time Complexity:O(N) Space Complexity:O(N)

int solve2(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int limit = 1; limit < 3; limit++)
            {
                int profit = 0;

                if (buy)
                {
                    int buyIncluded = -prices[index] + dp[index + 1][0][limit];
                    int buySkip = dp[index + 1][1][limit];
                    profit = max(buyIncluded, buySkip);
                }
                else
                {
                    int sellIncluded = prices[index] + dp[index + 1][1][limit - 1];
                    int sellSkip = dp[index + 1][0][limit];
                    profit = max(sellIncluded, sellSkip);
                }

                dp[index][buy][limit] = profit;
            }
        }
    }

    return dp[0][1][2]; // 1: buy, 2:Limit
}

// Space Optimization: Time Complexity:O(N)  Space Complecity:O(1)

int solve3(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> curr(2, vector<int>(3, 0));
    vector<vector<int>> next(2, vector<int>(3, 0));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int limit = 1; limit < 3; limit++)
            {
                int profit = 0;

                if (buy)
                {
                    int buyIncluded = -prices[index] + next[0][limit];
                    int buySkip = next[1][limit];
                    profit = max(buyIncluded, buySkip);
                }
                else
                {
                    int sellIncluded = prices[index] + next[1][limit - 1];
                    int sellSkip = next[0][limit];
                    profit = max(sellIncluded, sellSkip);
                }

                curr[buy][limit] = profit;
            }
            next = curr;
        }
    }

    return curr[1][2]; // 1: buy, 2:Limit
}

int main()
{

    return 0;
}