#include <iostream>
#include <vector>
#include <queue>

// All operations of KQueues are in O(1) time.

class KQueues
{
private:
    int *arr;
    int *front;
    int *rear;
    int *next;
    int free;
    int n, k;

public:
    KQueues(int n, int k)
    {
        arr = new int[n];
        next = new int[n];
        rear = new int[k];
        front = new int[k];

        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
        }

        for (int i = 0; i < n; i++)
            next[i] = i + 1;

        next[n - 1] = -1;

        free = 0;
        this->n = n;
        this->k = k;
    }
    void enqueue(int data, int s)
    {
        if (free == -1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        int index = free;
        arr[index] = data;

        free = next[index];

        if (front[s] == -1)
        {
            front[s] = index;
        }
        else
        {
            next[rear[s]] = index;
        }

        next[index] = -1;

        rear[s] = index;
    }

    int dequeue(int s)
    {
        if (front[s] == -1)
        {
            cout << "Empty Queue" << endl;
            return -1;
        }

        int i = front[s];

        front[s] = next[i];

        next[i] = free;
        free = i;

        return arr[i];
    }

    bool isEmpty(int s)
    {
        if (front[s] == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (free == -1)
            return true;
        else
            return false;
    }
};
using namespace std;
int main()
{

    return 0;
}