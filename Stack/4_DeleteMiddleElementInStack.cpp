#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// in case of even, delete Rightmost element

// Can also use Temp. Stack instead of vector data structure

// Time Complexity:O(N) Space Complexity:O(N)
void deleteMiddle(stack<int> &inputStack)
{
    int stackSize = inputStack.size();
    int mid = stackSize / 2;
    vector<int> v;

    while (mid > 0)
    {
        int currentElement = inputStack.top();
        v.push_back(currentElement);
        inputStack.pop();
        mid--;
    }

    if (stackSize % 2 == 0 && !inputStack.empty())
    {
        v.pop_back();
    }
    else if (stackSize % 2 != 0 && !inputStack.empty())
        inputStack.pop();

    int size = v.size();

    for (int i = size - 1; i >= 0; i--)
    {
        inputStack.push(v[i]);
    }
}

void deleteMiddleUtil1(stack<int> &inputStack, int N, int count)
{
    // Base Case
    if (count == N / 2)
    {
        inputStack.pop();
        return;
    }

    int currelement = inputStack.top();
    inputStack.pop();
    deleteMiddleUtil(inputStack, N, count + 1);
    inputStack.push(currelement);
}

// Using Recursion
// [1,2,3,4,5] N=4 --> [1,2,3,4]   {i is present at top of stack}
// [1,2,3,4] N=3 --> [1,3,4]
void deleteMiddleUtil(stack<int> &inputStack, int N, int count)
{
    if (inputStack.empty())
        return;

    int currelement = inputStack.top();
    inputStack.pop();
    deleteMiddleUtil(inputStack, N, count + 1);
    if (count != N / 2)
    {
        inputStack.push(currelement);
    }
}

// Time Complexity:O(N) Space Complexity:O(N)

void deleteMiddele1(stack<int> &inputStack, int N)
{
    int count = 0;
    deleteMiddleUtil(inputStack, N, count);
}

int main()
{

    return 0;
}