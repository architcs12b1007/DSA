#include <iostream>
#include <stack>
using namespace std;
// Given a string of balanced expressions, find if it contains a redundant parenthesis or not. A set of parenthesis is redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. Print ‘Yes‘ if redundant, else ‘No‘.

// Note: Expression may contain '+', '*', '–' and '/' operators and lowercase English letters.Given expression is valid and there are no white spaces present.

// i/p: str = "((a+b))""    o/p:YES   {around a+b}
// i/p: str = "(a+(b)/c)"   o/p:YES  {around b}
// i/p: str = "(a+b)""      o/p:NO
// Approach: if there is some operators between brackets, then it is NOT redundant
// Time Complexity:O(N), Space Complexity:O(N)
bool findRedundantBrackets(string &s)
{
    stack<char> ops, values;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            ops.push(s[i]);
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            values.push(s[i]);
        }
        else
        {
            if (!ops.empty() && ops.top() == '(')
                return true;

            while (!ops.empty() && ops.top() != '(')
            {
                if (values.empty())
                    return true;

                values.pop();

                if (values.empty())
                    return true;

                char operation = ops.top();
                ops.pop();
                if (operation == '(')
                    return true;
            }
            if (!ops.empty())
                ops.pop();
        }
    }

    return false;
}

// Approach: if there is some operators between brackets, then it is NOT redundant
bool findRedundantBrackets1(string &s)
{
    stack<char> ops;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            ops.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!ops.empty() && ops.top() == '(')
                return true;

            while (!ops.empty() && ops.top() != '(')
            {
                ops.pop();
            }

            if (!ops.empty())
                ops.pop();
        }
    }

    return false;
}

int main()
{

    return 0;
}