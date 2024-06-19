#include <iostream>
#include <vector>

using namespace std;

// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

//  Input: s = "aa", p = "a"    Output: false
// Input: s = "aa", p = "*"   Output: true

// Time complexity: O(2*(max(m,n)))
bool solve(string &s, string &p, int i, int j)
{
    if (i < 0 && j < 0) // both empty or both reach at end
    {
        return true;
    }

    if (i >= 0 && j < 0)
    { // pattern empty or exhausted
        return false;
    }

    if (i < 0 && j >= 0) // string empty or exhausted {s=ab  p=dcab  OR s=ab p=**ab)
    {
        for (int k = 0; k >= j; k++)
        {
            if (p[k] != '*') // check it contains all * or nor bcoz we can take it empty
                return false;
        }
        return true;
    }

    if (s[i] == p[j] || p[j] == '?') // match case
    {
        return solve(s, p, i - 1, j - 1);
    }
    else if (p[j] == '*')
    {
        bool emptyAns = solve(s, p, i, j - 1); // when * takes empty character
        bool MatchAns = solve(s, p, i - 1, j); // when * matches 1 character

        return (emptyAns || MatchAns);
    }
    else
    {
        return false; // not matches
    }
}

bool isMatch(string s, string p)
{
    int index1 = s.length() - 1;
    int index2 = p.length() - 1;
    return solve(s, p, index1, index2);
}

// Memoization: Time:O(M*N)  Space:O(M*N)

bool solve1(string &s, string &p, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0) // both empty or both reach at end
    {
        return true;
    }

    if (i >= 0 && j < 0)
    { // pattern empty or exhausted
        return false;
    }

    if (i < 0 && j >= 0) // string empty or exhausted {s=ab  p=dcab  OR s=ab p=**ab)
    {
        for (int k = 0; k >= j; k++)
        {
            if (p[k] != '*') // check it contains all * or nor bcoz we can take it empty
                return false;
        }
        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == p[j] || p[j] == '?') // match case
    {
        return dp[i][j] = solve1(s, p, i - 1, j - 1, dp);
    }
    else if (p[j] == '*')
    {
        bool emptyAns = solve1(s, p, i, j - 1, dp); // when * takes empty character
        bool MatchAns = solve1(s, p, i - 1, j, dp); // when * matches 1 character

        return dp[i][j] = (emptyAns || MatchAns);
    }
    else
    {
        return dp[i][j] = false; // not matches
    }
}

bool isMatch1(string s, string p)
{
    int index1 = s.length() - 1;
    int index2 = p.length() - 1;
    vector<vector<int>> dp(index1 + 1, vector<int>(index2 + 1, -1));
    return solve1(s, p, index1, index2, dp);
}

// Tabulation: Bototom up:   Time:O(M*N)  Space:O(M*N)

bool isMatch2(string s, string p)
{
    int n1 = s.length();
    int n2 = p.length();

    vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, 0)); // 1-index dp

    dp[0][0] = 1;

    for (int j = 1; j <= n2; j++)
    {
        if (p[j - 1] == '*')
            dp[0][j] = 1;
        else
            break;
    }

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return dp[n1][n2];
}

// Space optimzation: Time:O(m*n)  Space:O(m)

bool isMatch3(string s, string p)
{
    int n1 = s.length();
    int n2 = p.length();

    vector<bool> curr(n2 + 1, 0), prev(n1 + 1, 0); // 1-index dp

    prev[0] = 1;

    for (int j = 1; j <= n2; j++)
    {
        if (p[j - 1] == '*')
            prev[j] = 1;
        else
            break;
    }

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            {
                curr[j] = prev[j - 1];
            }
            else if (p[j - 1] == '*')
            {
                curr[j] = (prev[j] || curr[j - 1]);
            }
            else
            {
                curr[j] = 0;
            }
        }
        // curr[0] = 0; already initialised it at beginning
        prev = curr;
    }

    return prev[n2];
}
int main()
{

    return 0;
}