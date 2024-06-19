#include <iostream>
#include <vector>

using namespace std;

// prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

// Approach: Each Transaction {Buy, Sell}. same as Probelem 2 but decrease fee in sell part.

int maxProfit(vector<int> &prices, int fee)
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
                newSell = max(prices[i] + buy - fee, sell);
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