#include <iostream>
#include <stack>
using namespace std;

void pushAtCorrectPosiiton(stack<int> &stack, int x)
{
    if (stack.empty())
    {
        stack.push(x);
        return;
    }
    int top = stack.top();

    if (top <= x)
    {
        stack.push(x);
        return;
    }
    stack.pop();

    pushAtCorrectPosiiton(stack, x);

    stack.push(top);
}

// Time Complexity: O(N^2) Space Complexity:O(N)
void sortStack(stack<int> &stack)
{
    // Write your code here
    if (stack.empty())
        return;

    int topElement = stack.top();
    stack.pop();

    sortStack(stack);

    pushAtCorrectPosiiton(stack, topElement);
}

int main()
{

    return 0;
}