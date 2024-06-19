#include <iostream>
#include <vector>

using namespace std;

// prices[i] is the price of a given stock on the ith day.

// Maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. If you can not achieve any profit, return 0;

// Time Complexity:O(N) Space Complexity:O(1)

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    int profit = 0;
    int miniBuy = INT_MAX;

    for (int sellIndex = 1; sellIndex < n; sellIndex++)
    {
        miniBuy = min(miniBuy, prices[sellIndex - 1]);

        int diff = prices[sellIndex] - miniBuy;

        profit = max(profit, diff);
    }

    return profit;
}

int main()
{

    return 0;
}