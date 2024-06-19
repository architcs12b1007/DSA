#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Time Complexity: O(N)  Space Complexity:O(K)
queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> s;
    int size = q.size();

    for (int i = 0; i < k; i++)
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

    int remainingSize = size - k;

    while (remainingSize > 0)
    {
        int front = q.front();
        q.pop();
        q.push(front);
        remainingSize--;
    }

    return q;
}

int main()
{

    return 0;
}