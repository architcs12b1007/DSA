#include <iostream>
#include <stack>
using namespace std;

// Time Complexity:O(N) Space Complexity:O(N)

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    stack<int> temp;

    while (!myStack.empty())
    {
        int topElement = myStack.top();
        myStack.pop();
        temp.push(topElement);
    }

    myStack.push(x);

    while (!temp.empty())
    {
        int topElement = temp.top();
        temp.pop();
        myStack.push(topElement);
    }

    return myStack;
}

stack<int> pushAtBottomRecursion(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return myStack;
    }

    int topElement = myStack.top();
    myStack.pop();
    pushAtBottomRecursion(myStack, x);

    myStack.push(topElement);
    return myStack;
}

int main()
{

    return 0;
}