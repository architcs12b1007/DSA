#include <iostream>
#include <vector>

using namespace std;

// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:
// Insert a character
// Delete a character
// Replace a character

// Input: word1 = "horse", word2 = "ros"
// Output: 3  {replace'h' with 'r', remove'r', remove 's'}

// Time: O(3^m)  Space:O(1)
int solve(string &word1, string &word2, int i, int j)
{
    if (i >= word1.length()) // word1 is empty or its index out of range
    {
        return word2.length() - j;
    }

    if (j >= word2.length()) // word2 is empty or its index out of range
    {
        return word1.length() - i;
    }

    if (word1[i] == word2[j])
    {
        return solve(word1, word2, i + 1, j + 1);
    }
    else
    {

        int insertOp = solve(word1, word2, i, j + 1);     // insert
        int updateOp = solve(word1, word2, i + 1, j + 1); // update
        int deleteOp = solve(word1, word2, i + 1, j);     // delete

        return 1 + min(insertOp, min(updateOp, deleteOp));
    }
}

int minDistance(string word1, string word2)
{
    int index1 = 0;
    int index2 = 0;

    return solve(word1, word2, index1, index2);
}

// Memoization: Time:O(N*M)  Space:O(N*M)

int solve1(string &word1, string &word2, int i, int j, vector<vector<int>> &dp)
{
    if (i >= word1.length())
    {
        return word2.length() - j;
    }

    if (j >= word2.length())
    {
        return word1.length() - i;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (word1[i] == word2[j])
    {
        return dp[i][j] = solve1(word1, word2, i + 1, j + 1, dp);
    }
    else
    {

        int insertOp = solve1(word1, word2, i, j + 1, dp);     // insert
        int updateOp = solve1(word1, word2, i + 1, j + 1, dp); // update
        int deleteOp = solve1(word1, word2, i + 1, j, dp);     // delete

        return dp[i][j] = 1 + min(insertOp, min(updateOp, deleteOp));
    }
}

int minDistance1(string word1, string word2)
{
    int index1 = 0;
    int index2 = 0;

    int n = word1.length();
    int m = word2.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return solve1(word1, word2, index1, index2, dp);
}

// Tabulation:  Time:O(N*M)  Space:O(N*M)

int minDistance2(string word1, string word2)
{
    int n = word1.length();
    int m = word2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= m; i++)
    {
        dp[n][i] = m - i;
    }

    for (int i = 0; i <= n; i++)
    {
        dp[i][m] = n - i;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (word1[i] == word2[j])
            {
                dp[i][j] = dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i + 1][j + 1], min(dp[i + 1][j], dp[i][j + 1]));
            }
        }
    }

    return dp[0][0];
}

// Space Optimization:  Time:O(N*M)  Space:O(N)

int minDistance2(string word1, string word2)
{
    int n = word1.length();
    int m = word2.length();

    vector<int> curr(m + 1), next(m + 1);

    for (int i = 0; i <= m; i++)
    {
        next[i] = m - i;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (word1[i] == word2[j])
            {
                curr[j] = next[j + 1];
            }
            else
            {
                curr[j] = 1 + min(next[j + 1], min(next[j], curr[j + 1]));
            }
        }
        curr[m] = n - i; // impt part
        next = curr;
    }

    return next[0]; // NOT cuur[0] why?? if word1 is empty string, it fails
}
int main()
{

    return 0;
}