#include <iostream>
using namespace std;
// Return the count of number of palindromic substringd in a givrn string.

// Approach:  Think Each elemnt as middle and then expand leftwars and rightwards
//  Do with for even and odd length

// Time Complexity:O(N2) Space:O(1)
int palindromicSubstrings(string input)
{
    // Write your code here
    int ans = 0;
    int left = 0, right = 0;
    int n = input.length();

    // Odd planidrome substrings
    for (int i = 0; i < n; i++)
    {
        left = i;
        right = i;
        while (left >= 0 && right < n)
        {
            if (input[left] == input[right])
            {
                ans++;
                left--;
                right++;
            }
            else
            {
                break;
            }
        }
    }

    // even palindrome substrings

    for (int i = 0; i < n; i++)
    {
        left = i;
        right = i + 1;
        while (left >= 0 && right < n)
        {
            if (input[left] == input[right])
            {
                ans++;
                left--;
                right++;
            }
            else
            {
                break;
            }
        }
    }

    return ans;
}

// Recursion
int palindromicSubstrings1(string input)
{
}

int main()
{
    return 0;
}