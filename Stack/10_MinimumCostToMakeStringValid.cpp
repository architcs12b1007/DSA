#include <iostream>
#include <stack>
using namespace std;

// A string consist of either '{' or '}'. A string is valid if all parenthesis are valid.
// In one operation he can convert from '{' to '}' or viceversa & cost of this operation is 1.
// Determine min cost to make it valid and return -1 if it is not possible

// Approach: No of open brackets should be equal to no of closed brackets

// Time complexity:O(N),  Space:O(1) {Can also be done by stack: Space:O(N) }
int findMinimumCost(string str)
{
    int length = str.length();
    if (length % 2 != 0)
        return -1;
    else
    {
        int leftbracket = 0;
        int rightbracket = 0;
        for (int i = 0; i < length; i++)
        {
            if (str[i] == '{')
                leftbracket++;
            else
            {
                if (leftbracket > 0)
                    leftbracket--;
                else
                    rightbracket++;
            }
        }
        //  return ((leftbracket + 1) / 2) + ((rightbracket + 1) / 2);
        // 3 patterns are possible after removing valid parts:}}}, {{{, }}}{{{

        // when both are even
        if (leftbracket % 2 == 0)
            return (leftbracket + rightbracket) / 2;
        else // when both are odd;
            return 1 + (leftbracket + rightbracket) / 2;
    }
}

int main()
{

    return 0;
}