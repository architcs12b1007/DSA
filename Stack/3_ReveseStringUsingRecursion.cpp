#include <iostream>
#include <stack>
using namespace std;

// Properties of Stack: We can use it for reversal

// Time Complexity:O(N), Space Complexity:O(N)

string reverseStringUsingStack(string s)
{
    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }

    while (!st.empty())
    {
        char current = st.top();
        ans = ans + current; // ans.push_back(current);

        st.pop();
    }

    return ans;
}

int main()
{
    string s = "Hello Ji!";

    cout << reverseStringUsingStack(s);

    return 0;
}