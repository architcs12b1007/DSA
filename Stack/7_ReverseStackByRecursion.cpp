#include <iostream>
#include <stack>
using namespace std;

void pushAtBottomRecursion(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }

    int topElement = myStack.top();
    myStack.pop();
    pushAtBottomRecursion(myStack, x);

    myStack.push(topElement);
}

// Do it with Recursion and NOT allowed to use any extra space other than internal stack space due to recursion

// Time Complexity: O(N^2) Space Complexity: O(N)
void reverseStack(stack<int> &stack)
{
    // Write your code here
    if (stack.empty())
        return;

    int topElement = stack.top();
    stack.pop();

    reverseStack(stack);

    pushAtBottomRecursion(stack, topElement);
}

int main()
{

    return 0;
}