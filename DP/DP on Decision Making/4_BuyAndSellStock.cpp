#include <iostream>
#include <vector>

using namespace std;

// prices[i] is the price of a given stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Put limit=k in previous soltution.

// Time Complexity;O(N*K)  Space Complexity:O(K)

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> curr(2, vector<int>(k + 1, 0));
    vector<vector<int>> next(2, vector<int>(k + 1, 0));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int limit = 1; limit <= k; limit++)
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

    return curr[1][k]; // 1: buy, 2:Limit
}

// Approach 2: Use Operation No. if we have odd operation No. (BUY), even operation No. (SELL)
// Here is 2d dynamic programming problem

int solve(vector<int> &prices, int k, int index, int operationNo)
{
    if (index == prices.size())
        return 0;

    if (operationNo == 2 * k)
        return 0;

    int profit = 0;

    if (operationNo % 2 == 0)
    {
        int buyIncluded = -prices[index] + solve(prices, k, index + 1, operationNo + 1);
        int buySkip = solve(prices, k, index + 1, operationNo);

        profit = max(buyIncluded, buySkip);
    }
    else
    {
        int sellIncluded = prices[index] + solve(prices, k, index + 1, operationNo + 1);
        int sellSkip = solve(prices, k, index + 1, operationNo);

        profit = max(sellIncluded, sellSkip);
    }

    return profit;
}

int maxProfit1(vector<int> &prices, int k)
{

    int operationNo = 0;
    int index = 0;

    return solve(prices, k, index, operationNo);
}

int main()
{

    return 0;
}