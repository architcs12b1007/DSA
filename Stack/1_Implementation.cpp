#include <iostream>
using namespace std;
// A stack is a linear data structure where both insertion and deletion of elements take place at top.
// It follows LIFO(Last in First Out) and FILO(First In Last Out) approaches.

// Can be implmneted using array or Linked Lists
// Time: O(1) all operations
class Stack
{
public:
    // properties

    int *arr;
    int top;
    int size;

    Stack(int n)
    {
        arr = new int[n];
        top = -1;
        size = n;
    }

    // behaviors

    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack is already full." << endl;
            return;
        }

        top++;
        arr[top] = size;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is Empty";
            return;
        }

        top--;
    }

    int top()
    {
        if (top != -1)
            return arr[top];

        return -1;
    }

    int size()
    {
        return 1 + top;
    }

    bool isempty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
};

int main()
{

    return 0;
}