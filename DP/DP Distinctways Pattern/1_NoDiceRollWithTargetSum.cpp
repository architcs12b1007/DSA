#include <iostream>
#include <vector>

using namespace std;

// Given N dice each with M faces, numbered from 1 to M, find the number of ways to get sum X
// X is the summation of values on each face when all the dice are thrown.  1 <= M,N,X <= 50

// M = 2, N = 3, X = 6     Output:1

// Approach:  index: To epresent cube position
// For loop from 1 to M to pick 1 value from the given cube
long long solve(int dice, int faces, int target)
{

    if (target < 0)
        return 0;

    if (dice == 0 && target == 0)
        return 1;

    if (dice == 0 && target != 0)
        return 0;

    if (dice != 0 && target == 0)
        return 0;

    long long ans = 0;

    for (int j = 1; j <= faces; j++)
    {
        ans += solve(dice - 1, faces, target - j);
    }

    return ans;
}

long long noOfWays(int M, int N, int X)
{
    // code here

    return solve(M, N, X);
}

// Memoization: Time:(M*X*N)   Space:O(M*X)

long long solve1(int dice, int faces, int target, vector<vector<int>> &dp)
{

    if (target < 0)
        return 0;

    if (dice == 0 && target == 0)
        return 1;

    if (dice == 0 && target != 0)
        return 0;

    if (dice != 0 && target == 0)
        return 0;

    if (dp[dice][target] != -1)
        return dp[dice][target];

    long long ans = 0;

    for (int j = 1; j <= faces; j++)
    {
        ans += solve1(dice - 1, faces, target - j, dp);
    }

    dp[dice][target] = ans;
    return dp[dice][target];
}

// Tabulation:  Time:(M*X*N)   Space:O(M*X)

long long noOfWays1(int M, int N, int X)
{
    // code here

    vector<vector<long long>> dp(N + 1, vector<long long>(X + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= X; j++)
        {
            long long int sum = 0;
            for (int k = 1; k <= M; k++)
            {
                if (j - k >= 0)
                    sum += dp[i - 1][j - k];
            }
            dp[i][j] = sum;
        }
    }

    return dp[N][X];
}

// Space Optimization:  Time:(M*X*N)   Space:O(X)

long long noOfWays2(int M, int N, int X)
{
    // code here

    vector<long long> prev(X + 1, 0), curr(X + 1, 0);
    prev[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= X; j++)
        {
            long long int sum = 0;
            for (int k = 1; k <= M; k++)
            {
                if (j - k >= 0)
                    sum += prev[j - k];
            }
            curr[j] = sum;
        }
        prev = curr;
    }

    return prev[X];
}

int main()
{

    return 0;
}