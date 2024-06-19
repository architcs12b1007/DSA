#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Input Restricted Queue: A queue where insertion takes place at rear but pop is available at both sides (i.e. front and rear) {push_back, pop_front, pop_back}

// Output Restricted Queue: A queue where insertion takes place at rear & front but pop is available at front side. {push_back, push_front, pop_front}

// Doubly Ended Queue: A queue where insertion and deletion takes place at both ends (front & rear)
// {push_back, push_front, pop_front, pop_back}

class Deque
{
private:
    int *arr;
    int front, rear;
    int s;

public:
    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        arr=new int[n];
        s=n;
        front=-
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
    }
};
int main()
{

    return 0;
}