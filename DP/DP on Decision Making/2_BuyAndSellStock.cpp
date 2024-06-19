#include <iostream>
#include <vector>

using namespace std;

// prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

// prices = [7,1,5,3,6,4]
// Output: 7 {5-1=4; 6-3=3}

// prices:[8,6,5,3,2,1]  output:0

// Approach: It should be a combination of {Buy, Sell, Buy, Sell -----------}
// Take variable: Bool Buy-To indicate whether next step is Buy or Sell.
// Buy =0:next step is sell(we have to choices, either sell or ignore)
// Buy =1:next step is buy (we have 2 choices, either buy or ignore)
// Profit= Sell-Buy =Sell+(-Buy) {Buy add with -ve sign}
// if(buy): profit+=max(-prices[i]+solve(index+1,buy=0,prices),solve(index+1,buy=0,prices))
// else: profit+=max(prices[i]+solve(index+1,buy=0,prices),solve(index+1,buy=0,prices))

int solve(vector<int> prices, int index, int buy)
{
    if (index >= prices.size())
        return 0;

    int profit = 0;

    if (buy)
    {
        // max(buykaro,skipkro)
        profit = max(-prices[index] + solve(prices, index + 1, 0), solve(prices, index + 1, 1));
    }
    else
    {
        // max(sellkaro,skipkro)
        profit = max(prices[index] + solve(prices, index + 1, 1), solve(prices, index + 1, 0));
    }

    return profit;
}

int maxProfit(vector<int> prices)
{
    bool buy = 1;
    int index = 0;

    return solve(prices, index, buy);
}

// Add memoization: (Top-Down Solution) as index go from 0 to n-1
// Time Complexity:O(2*N), Space Complexity:O(2*N)

int solve1(vector<int> prices, int index, int buy, vector<vector<int>> &dp)
{
    if (index >= prices.size())
        return 0;

    if (dp[index][buy] != -1)
    {
        return dp[index][buy];
    }

    int profit = 0;

    if (buy)
    {
        profit = max(-prices[index] + solve1(prices, index + 1, 0, dp), solve1(prices, index + 1, 1, dp));
    }
    else
    {
        profit = max(prices[index] + solve1(prices, index + 1, 1, dp), solve1(prices, index + 1, 0, dp));
    }

    dp[index][buy] = profit;

    return dp[index][buy];
}

int maxProfit1(vector<int> prices)
{
    bool buy = 1;
    int index = 0;
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));

    return solve1(prices, index, buy, dp);
}

// Tabulation: Bottom up  Time Complexity:O(2*N) Space Complexity:O(2*N)

int solve2(vector<int> prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    // for (int i = 0; i < 2; i++)
    // {
    //     dp[n][i] = 0;
    // }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++) // j=1 buy, j=0 sell
        {

            if (j)
            {
                dp[i][j] = max(-prices[i] + dp[i + 1][!j], dp[i + 1][j]);
            }
            else
            {
                dp[i][j] = max(prices[i] + dp[i + 1][!j], dp[i + 1][j]);
            }
        }
    }

    return dp[0][1]; // 1: for buy (first, we need to but share)
}

// Space optimization: Time:O(2*N) Space:O(1)

int solve3(vector<int> prices)
{
    int n = prices.size();

    int buy = 0, sell = 0;
    int newBuy, newSell;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++) // j=1 buy, j=0 sell
        {

            if (j)
            {
                newBuy = max(-prices[i] + sell, buy);
            }
            else
            {
                newSell = max(prices[i] + buy, sell);
            }
        }
        buy = newBuy;
        sell = newSell;
    }

    return buy;
}

int main()
{

    return 0;
}