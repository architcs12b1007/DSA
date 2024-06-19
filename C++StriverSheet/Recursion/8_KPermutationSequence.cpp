#include <bits/stdc++.h>
using namespace std;

// Given N and K, where N is the sequence of numbers from 1 to N([1,2,3….. N]) find the Kth permutation sequence.

// Input: N = 3, K = 3

// Output: "213"

// Approach 1:Store all permuations in data structure using recursion and then sort it and return Kth sequence from it. Time Complexity:O(N!*N + N!*log(N!))

// Time Complexity:O(N^2), Space Complexity:O(N)

string kthPermutation(int n, int k)
{
    string ans = "";

    int fact = 1;
    vector<int> nums;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        nums.push_back(i);
    }

    nums.push_back(n);
    k = k - 1; // 0-indexing

    while (true)
    {
        ans += to_string(nums[k / fact]);
        nums.erase(nums.begin() + (k / fact)); // deletion at speciifc position. O(N)
        if (nums.size() == 0)
            break;
        k = k % fact;
        fact = fact / nums.size();
    }

    return ans;
}
int main()
{

    return 0;
}