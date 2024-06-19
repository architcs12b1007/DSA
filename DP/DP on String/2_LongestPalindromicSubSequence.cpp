#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// finding a maximum-length subsequence of a given string that is also a Palindrome.

// Input: s = "bbbab"
// Output: 4 {bbbb}

// Approach: Find reverse of givrn string and then find the longest coomon subsequence between 2 strings

// Time Complexity:O(N2) Space:O(N),  where N is length of string
int longestPalindromeSubseq(string text1)
{
    string text2 = text1;
    reverse(text2.begin(), text2.end());

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

    return 0;
}