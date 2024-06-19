#include <iostream>
using namespace std;

// Approach 1: Consider all substrings of text1(m^2 substrings)  and for each substring, check whether it is substring of another substing(we can do do in O(N) time using Rabin-Karp Algo)
// Time Complexity:O(N*M^2) Space;O(1)

// Approach2: Recursion

// Time Complexity;O(2^max(n,m)) Auxillary Space:O(1)
int solve(string text1, string text2, int i, int j, int count)
{
    if (text1.length() || text2.length())
        return count;

    if (text1[i] == text2[j])
    {
        count = solve(text1, text2, i + 1, j + 1, count + 1);
    }

    int count1 = solve(text1, text2, i, j + 1, count + 1);
    int count2 = solve(text1, text2, i + 1, j, count + 1);

    return max(count, max(count1, count2));
}

int longestCommonSubstring(string text1, string text2)
{
    int index1 = 0;
    int index2 = 0;
    int count = 0;
    return solve(text1, text2, index1, index2, count);
}

// Dynamic Programming:

int main()
{

    return 0;
}