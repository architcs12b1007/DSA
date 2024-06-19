#include <iostream>
using namespace std;
// Same as implemented N Stacks in an array
// 0<=s<=10^5
class TwoStack
{

public:
    // Initialize TwoStack.
    int *arr;
    int top1, top2;
    int *next;
    int free;
    int n;

    TwoStack(int s)
    {
        // Write your code here.
        n = s;
        if (s > 0)
        {
            arr = new int[s];
            next = new int[s];

            for (int i = 0; i < s; i++)
                next[i] = i + 1;

            next[s - 1] = -1;
        }
        top1 = -1;
        top2 = -1;
        free = 0;
    }

    // Push in stack 1.
    void push1(int num)
    {
        // Write your code here.
        if (free != -1 && n > 0)
        {
            int i = free;
            free = next[i];
            arr[i] = num;
            next[i] = top1;
            top1 = i;
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        // Write your code here.
        if (free != -1 && n > 0)
        {
            int i = free;
            free = next[i];
            arr[i] = num;
            next[i] = top2;
            top2 = i;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        // Write your code here.
        if (top1 == -1 || n == 0)
            return -1;
        else
        {
            int i = top1;
            top1 = next[i];

            next[i] = free;
            free = i;

            return arr[i];
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        // Write your code here.
        if (top2 == -1 || n == 0)
            return -1;
        else
        {
            int i = top2;
            top2 = next[i];

            next[i] = free;
            free = i;
            return arr[i];
        }
    }
};

// Another Approach: No need of free and next variable while insert elemnts in array
// for stack1 from left to right and start from index 0 {top1=0}
// for stack2 from right to left and start from index n-1 {top2=n}

class TwoStack
{
    int *arr;
    int top1;
    int top2;
    int size;

public:
    // Initialize TwoStack.
    TwoStack(int s)
    {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    // Push in stack 1.
    void push1(int num)
    {
        // atleast a empty space present
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{

    return 0;
}