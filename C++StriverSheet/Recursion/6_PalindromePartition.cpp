#include <bits/stdc++.h>
using namespace std;

// You are given a string s, partition it in such a way that every substring is a palindrome. Return all such palindromic partitions of s.

// Input: s = “aab”

// Output: [ ["a","a","b"], ["aa","b"] ]

bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }

    return true;
}

void solve(string s, vector<vector<string>> &ans, vector<string> &temp, int index)
{
    if (index == s.length())
    {
        ans.push_back(temp);
        return;
    }

    for (int i = index; i < s.length(); i++)
    {
        if (isPalindrome(s, index, i))
        {
            temp.push_back(s.substr(index, i - index + 1)); // first position, length of substring
            solve(s, ans, temp, i + 1);
            temp.pop_back();
        }
    }
}

// Approach: Create partitions at each recursion call.(First level of recursion: 1 partition, 2nd level of recursion: 2 parttion) and check whther it is a palindrome or not

// Time Complexity: O( (2^n) *k*(n/2) )

// Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> temp;

    solve(s, ans, temp, 0);
    return ans;
}
int main()
{

    return 0;
}