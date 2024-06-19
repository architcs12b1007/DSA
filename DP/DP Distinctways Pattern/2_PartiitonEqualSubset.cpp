#include <iostream>
#include <vector>
using namespace std;

// Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same. return 1 if yes possible else return 0

// arr = {1, 5, 11, 5}  Output: YES  {1,5,5} {11}

// arr = {1, 3, 5}   Output: NO  {NOT POSSIBLE}

// Approach: Find total sum of array. if is even then need to find elements in array such that its sum id target/2, otherwise can not parttion it into wqual sum.

int solve(int arr[], int N, int target)
{
    if (target == 0)
        return 1;
    else if (target < 0)
        return 0;

    if (N < 0)
        return 0;

    int includeElement = solve(arr, N - 1, target - arr[N]);
    int excludeElement = solve(arr, N - 1, target);

    return includeElement || excludeElement;
}

int equalPartition(int N, int arr[])
{
    // code here

    int target = 0;

    for (int i = 0; i < N; i++)
    {
        target += arr[i];
    }

    if (target % 2 != 0)
        return 0;

    return solve(arr, N - 1, target / 2);
}

// Memoization: Time:O(N*Sum of elements)  Space:O(N*Sum of elements)

int solve1(int arr[], int N, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;
    else if (target < 0)
        return 0;

    if (N < 0)
        return 0;

    if (dp[N][target] != -1)
        return dp[N][target];

    int pickElement = solve1(arr, N - 1, target - arr[N], dp);
    int NotpickElement = solve1(arr, N - 1, target, dp);

    return dp[N][target] = pickElement || NotpickElement;
}

int equalPartition1(int N, int arr[])
{
    // code here

    int target = 0;

    for (int i = 0; i < N; i++)
    {
        target += arr[i];
    }

    if (target % 2 != 0)
        return 0;

    vector<vector<int>> dp(N, vector<int>(1 + (target / 2), 0));

    return solve1(arr, N - 1, target / 2, dp);
}

// Tabulation: Time:O(N*Sum of elements)  Space:O(N*Sum of elements)

int equalPartition2(int N, int arr[])
{
    // code here

    int target = 0;

    for (int i = 0; i < N; i++)
    {
        target += arr[i];
    }

    if (target % 2 != 0)
        return 0;

    target = target / 2;

    vector<vector<int>> dp(N + 1, vector<int>(1 + target, 0)); // 1-indexed

    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (j - arr[i] >= 0)
                dp[i][j] = dp[i - 1][j - arr[i]] || dp[i - 1][j];
        }
    }

    return dp[N][target];
}

// Space Optimization: Time:O(N*Sum of elements)  Space:O(Sum of elements)

int equalPartition3(int N, int arr[])
{
    // code here

    int target = 0;

    for (int i = 0; i < N; i++)
    {
        target += arr[i];
    }

    if (target % 2 != 0)
        return 0;

    target = target / 2;

    vector<int> prev(1 + target, 0), curr(1 + target, 0); // 1-indexed

    prev[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (j - arr[i] >= 0)
                curr[j] = prev[j - arr[i]] || prev[j];
        }
        curr[0] = 1;
        prev = curr;
    }

    return prev[target];
}
int main()
{

    return 0;
}