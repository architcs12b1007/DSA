#include <iostream>
#include <vector>
using namespace std;

// Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

// Example 1:

// Input:
// S = i.like.this.program.very.much
// Output: much.very.program.this.like.i

// Time Complexity: O(N) Space Complexity:O(N)

string reverseWords(string S)
{
    // code here
    string ans;
    int n = S.length();

    reverse(S.begin(), S.end());

    int i = 0;

    while (i < n)
    {
        string temp;

        while (i < n && S[i] != '.')
        {
            temp.push_back(S[i]);
            i++;
        }

        reverse(temp.begin(), temp.end());
        ans += temp;

        if (i != n)
        {
            ans += '.';
        }

        i++;
    }

    return ans;
}

int main()
{

    return 0;
}