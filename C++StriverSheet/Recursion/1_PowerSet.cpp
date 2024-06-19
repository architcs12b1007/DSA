#include <bits/stdc++.h>

using namespace std;

// Given a string, find all the possible subsequences of the string.

// Time Complexity:O(2^N* N)    Space Complexity:O(1)

void printAllSubsequences(string s)
{
    int len = s.length();
    for (int i = 1; i < (1 << len); i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (i & (1 << j))
            {
                cout << s[j];
            }
        }
        cout << "  ";
    }
}

// Using Recursion: 2 cases are possible: Either you take the character or you cannot pick the character & move to next character

// Time Complexity: O(2^N)  Space Complexity:O(N), N is length of string

void printAllSubsequences1(string s, int index, string &ans)
{
    if (index == s.length())
    {
        cout << ans << "  ";
        return;
    }

    ans = ans + s[index]; // pick
    printAllSubsequences1(s, index + 1, ans);
    ans.pop_back(); // remove character while backtracking
    printAllSubsequences1(s, index + 1, ans);
}

int main()
{
    string s = "abc";
    string ans = "";
    printAllSubsequences(s);
    cout << endl;
    printAllSubsequences1(s, 0, ans);
    return 0;
}