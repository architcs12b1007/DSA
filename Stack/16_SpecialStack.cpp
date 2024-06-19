#include <iostream>
#include <stack>
using namespace std;

// Design a stack that supports getMin() in O(1) time and O(1) extra space

// Operations like pop, top and getMin  will always be called on non-empty stacks.

// Approach 1:Use stack data structure to store min elements whenever an elements is pushed & when an element is popped, we get min element in O(1) time. Space Complexity:O(N)

// Approach 2:We define a variable minEle that stores the current minimum element in the stack.

// Now the interesting part is, how to handle the case when the minimum element is removed.
// To handle this, we push “2x – minEle(previous min element)” into the stack instead of x  (when x<minEle)
// so that the previous minimum element can be retrieved using the current minEle and its value stored in the stack {2*minElement-stacktopelement}

class SpecialStack
{
public:
    stack<int> s;
    int mini;

    void push(int data)
    {
        // Implement the push() function.
        if (s.empty())
        {
            s.push(data);
            mini = data;
            return;
        }

        if (data < mini)
        {
            int new_element = 2 * data - mini;
            s.push(new_element);
            mini = data;
        }
        else
        {
            s.push(data);
        }
    }

    void pop()
    {
        // Implement the pop() function.
        if (s.empty())
            return;

        if (s.top() < mini)
        {
            mini = 2 * mini - s.top();
        }

        s.pop();
    }

    int top()
    {
        // Implement the top() function.

        if (!s.empty())
        {
            if (s.top() < mini)
            {
                return mini;
            }
            else
            {
                return s.top();
            }
        }
        return INT_MAX;
    }

    int getMin()
    {
        // Implement the getMin() function.
        if (!s.empty())
        {
            return mini;
        }
        return INT_MAX;
    }
};

int main()
{

    return 0;
}

// How does this approach work?
// When the element(x) to be inserted is less than minEle, we insert “2x – minEle”. The important thing to note is, that 2x – minEle will always be less than x (proved below), i.e., new minEle and while popping out this element we will see that something unusual has happened as the popped element is less than the minEle. So we will be updating minEle