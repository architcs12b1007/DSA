#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// N candies, candies[i] prices of ith candies and for every one candy, you get K other candies for free

// Firstly, you have to find what is the minimum amount of money you have to spend to buy all the N different candies. Secondly, you have to find what is the maximum amount of money you have to spend to buy all the N different candies.  1 <= N <= 100000, 0 <= K <= N-1

// Time Complexity:O(NlogN) Space:O(1)
vector<int> candyStore(int candies[], int N, int K)
{
    // Write Your Code here
    int minAmount = 0, maxAmount = 0;
    vector<int> ans;

    sort(candies, candies + N);

    int NoCandies = N / (K + 1); //  1 candies gives K candies free, t candies gives Kt candies free
    // so, t<=N/(1+K)

    if (N % (1 + K) != 0)
    {
        NoCandies++;
    }

    for (int i = 0; i < NoCandies; i++)
    {
        minAmount += candies[i];
        maxAmount += candies[N - i - 1];
    }

    ans.push_back(minAmount);
    ans.push_back(maxAmount);
    return ans;
}
int main()
{

    return 0;
}