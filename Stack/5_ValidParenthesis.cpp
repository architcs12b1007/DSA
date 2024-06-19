#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

// Given a strin in form of '(' '{' '[' ']' '}' ')', return true if string is balanced, otherwise false.
// eg: i/p: [{]}  o/p: FALSE
// i/p: }{  o/p:FALSE

// Time Complexity:O(N)  Space Complexity:O(N)

bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> st;
    unordered_map<char, char> hashMap = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {

            if (st.empty())
                return false;

            char currentElement = s[i];

            // check the opening brace for every closing brace.
            if (currentElement == hashMap[st.top()]) // st.top()=='(' && currentElement==')' || st.top()=='[' && currentElement==']' || st.top()=='{' && currentElement=='}'
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    // return st.empty();
    if (st.empty())
        return true;
    else
        return false;
}

int main()
{

    return 0;
}