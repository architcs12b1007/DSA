#include <iostream>
#include <vector>

using namespace std;

// Do movement if string character matches or not (Do movement as per recursive relation)
string printlcs(string text1, string text2, vector<vector<int>> &dp)
{
    int n1 = text1.length();
    int n2 = text2.length();
    string lcs;

    int i = 0, j = 0;

    // Time: O(N+M)
    while (i < n1 && j < n2)
    {

        if (text1[i] == text2[j])
        {
            lcs.push_back(text1[i]);
            i = i + 1;
            j = j + 1;
        }
        else
        {
            if (dp[i + 1][j] > dp[i][j + 1])
            {
                i = i + 1;
            }
            else // (dp[i+1][j] <= dp[i][j+1]) // if they are equal, move to any one place (& we have multile lcs)
            {
                j = j + 1;
            }
        }
    }

    return lcs;
}

//  find the length of their longest common subsequence. If there is no common subsequence, return 0.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// Input: text1 = "abcde", text2 = "ace"
// Output: 3    {ace}

// Total subsequences can be possible for a string: 2^N (either take first character or not, so we have 2 choices)

// Approach: Check the relation between the first characters of the strings that are not yet processed.

// Time Complexitty: O(2^(m*n)) Auxillary Space;O(1)
int solve(string text1, string text2, int index1, int index2)
{

    if (index1 >= text1.length() || index2 >= text2.length())
        return 0;

    if (text1[index1] == text2[index2])
    {
        return 1 + solve(text1, text2, index1 + 1, index2 + 1);
    }
    else
    {
        return max(solve(text1, text2, index1 + 1, index2), solve(text1, text2, index1, index2 + 1));
    }
}

int longestCommonSubsequence(string text1, string text2)
{
    int index1 = 0;
    int index2 = 0;

    return solve(text1, text2, index1, index2);
}

// Memoization:  // Time Complexitty: O(m*n) Auxillary Space:O(m*n)

int solve1(string &text1, string &text2, int index1, int index2, vector<vector<int>> &dp)
{

    if (index1 >= text1.length() || index2 >= text2.length())
        return 0;

    if (dp[index1][index2] != -1)
    {
        return dp[index1][index2];
    }

    if (text1[index1] == text2[index2])
    {
        return dp[index1][index2] = 1 + solve1(text1, text2, index1 + 1, index2 + 1, dp);
    }
    else
    {
        return dp[index1][index2] = max(solve1(text1, text2, index1 + 1, index2, dp), solve1(text1, text2, index1, index2 + 1, dp));
    }
}

int longestCommonSubsequence1(string text1, string text2)
{
    int index1 = 0;
    int index2 = 0;
    int n1 = text1.length();
    int n2 = text2.length();

    vector<vector<int>> dp(n1, vector<int>(n2, -1));

    return solve1(text1, text2, index1, index2, dp);
}

// Tabulation: Time Complexitty: O(m*n) Auxillary Space:O(m*n)

int solve2(string text1, string text2)
{
    int n1 = text1.length();
    int n2 = text2.length();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int index1 = n1 - 1; index1 >= 0; index1--)
    {
        for (int index2 = n2 - 1; index2 >= 0; index2--)
        {

            if (text1[index1] == text2[index2])
            {
                dp[index1][index2] = 1 + dp[index1 + 1][index2 + 1];
            }
            else
            {
                dp[index1][index2] = max(dp[index1 + 1][index2], dp[index1][index2 + 1]);
            }
        }
    }
    cout << printlcs(text1, text2, dp) << endl;
    return dp[0][0];
}

// Space Optimization : Time Complexitty: O(m*n) Auxillary Space:O(m)

int solve3(string text1, string text2)
{
    int n1 = text1.length();
    int n2 = text2.length();

    vector<int> curr(n2 + 1, 0), next(n2 + 1, 0);

    for (int index1 = n1 - 1; index1 >= 0; index1--)
    {
        for (int index2 = n2 - 1; index2 >= 0; index2--)
        {

            if (text1[index1] == text2[index2])
            {
                curr[index2] = 1 + next[index2 + 1];
            }
            else
            {
                curr[index2] = max(next[index2], curr[index2 + 1]);
            }
        }
        next = curr;
    }

    return curr[0];
}

int main()
{

    string s1 = "abcdef";
    string s2 = "acwdregf";
    cout << solve2(s1, s2) << endl;
}

// Longest CommonSubSequence of 3 strings:  Time Conmplexity:O(n*m*k) Space:O(n*m*K)  3-DP

// if X[i] == Y[j] ==Z[k]) then
// return 1 + solve(X,Y,Z,i+1,j+1,k+1)
// else (or X[i] != Y[j] || X[i] != Z[k]   || Y[j] !=Z[k])
//  return max(solve(X,Y,Z,i+1,j,k), solve(X,Y,Z,i,j+1,k), solve(X,Y,Z,i,j,k+1))
