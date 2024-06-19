#include <iostream>
#include <vector>
#include <queue>
#include <stack>

// Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

// Examples:

// Input :  1 2 3 4
// Output : 1 3 2 4

// Input : 11 12 13 14 15 16 17 18 19 20
// Output : 11 16 12 17 13 18 14 19 15 20

using namespace std;

// Approach 1: Fetch 1st half elements from queue and put it into another queue. Then fetch front elemnt of both queue simultanously and insert it into original queue.
// Time complecity:O(N)  Space Complexity:O(N/2)

void interLeaveQueue(queue<int> &q)
{
    int size = q.size();

    int s = size / 2;

    queue<int> temp;

    while (s-- > 0)
    {
        int front = q.front();
        q.pop();
        temp.push(front);
    }

    while (!temp.empty())
    {
        int front1 = temp.front();
        temp.pop();
        int front2 = q.front();
        q.pop();

        q.push(front1);
        q.push(front2);
    }
}
// Constraint: Only Stack can be used as an auxillary space:
// Time:O(N)  Space:O(N)

void interLeaveQueue1(queue<int> &q)
{
    int size = q.size();
    int s = size / 2;
    stack<int> st;

    // Push first half elements into stack
    while (s-- > 0)
    {
        int front = q.front();
        q.pop();
        st.push(front);
    }

    // reverse the elements of stack
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        q.push(top);
    }

    s = size / 2;

    while (s-- > 0)
    {
        int front = q.front();
        q.pop();
        q.push(front);
    }

    s = size / 2;

    while (s-- > 0)
    {
        int front = q.front();
        q.pop();
        st.push(front);
    }

    // Take 1 elements from stack and 1 from queue and insert it into queue

    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        int front = q.front();
        q.pop();

        q.push(top);
        q.push(front);
    }
}

int main()
{

    return 0;
}