// USING STL for implementation of heap

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // max heap
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << pq.top() << endl;

    pq.pop();

    cout << pq.top() << endl;
    cout << pq.size() << endl;

    // min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
}