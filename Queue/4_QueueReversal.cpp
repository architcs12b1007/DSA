#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Use stack data structure to reverse queue
// Time Complexity:O(N), Space Complexity:O(N)
queue<int> rev(queue<int> q)
{
    stack<int> s;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        s.push(front);
    }

    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        q.push(top);
    }

    return q;
}

// Using Recursion, Time Complexity:O(N) Space Complexity:o(N)
queue<int> rev1(queue<int> &q)
{
    if (q.empty())
        return q;

    int front = q.front();
    q.pop();
    rev1(q);
    q.push(front);

    return q;
}

int main()
{

    return 0;
}