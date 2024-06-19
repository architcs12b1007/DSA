#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
        front = -1;
        rear = 0;
    }

    void enqueue(int data)
    {
        if (rear == front)
        {
            // cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1)
        {
            front = rear;
        }

        arr[rear] = data;

        rear = (rear + 1) % s;
    }

    int dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        front = (front + 1) % s;

        if (front == rear)
        {
            front = -1;
        }
    }

    bool isEmpty()
    {
        if (front == -1)
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
        if (front == -1)
            return -1;
        else
            arr[front];
    }
};
int main()
{

    return 0;
}
