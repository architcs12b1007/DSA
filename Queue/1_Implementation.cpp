#include <iostream>
#include <vector>
#include <queue>

// A Queue is a linear Data structure that follows FIFO (First In First Out)
// {Two variables: front, rear}
// Element always insert in rear position
// Element always delete in front position

// We can implement queue using either ARRAY or LINKED LIST

class Queue
{
private:
    int *arr;
    int s;
    int rear, front;

public:
    Queue(int size)
    {
        arr = new int[size];
        s = size;
        front = 0;
        rear = 0;
    }

    void enqueue(int data)
    {
        if (rear == s)
        {
            // cout << "Queue Overflow" << endl;
            return;
        }

        arr[rear] = data;

        rear++;
    }

    int dequeue()
    {
        if (front == rear)
        {
            // cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = arr[front];

        front = front + 1;

        // If both at same postion, empty queue, so move front and rear to same location

        if (front == rear)
        {
            front = 0;
            rear = 0;
        }

        return ans;
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int front()
    {
        if (front == rear)
            return -1;
        else
            return arr[front];
    }
};

using namespace std;
int main()
{

    return 0;
}