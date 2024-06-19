#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given a value of V Rs and an infinite supply of each of the denominations {1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes.
// find the minimum number of coins and/or notes needed to make the change?

// Approach: Following greedy approach works only for the mentioned denomination, not for other denominations

// Time:O(target), Space:O(target)

vector<int> findMin(vector<int> denomination, int target)
{
    int n = denomination.size();
    sort(denomination.begin(), denomination.end());

    vector<int> ans;

    for (int i = n - 1; i >= 0; i--)
    {

        while (target >= denomination[i])
        {
            target -= denomination[i];
            ans.push_back(denomination[i]);
        }
    }
}

int main()
{

    return 0;
}