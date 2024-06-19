// Approach 1: 1)Sort the array and return arr[k-1]; Time Complexity:O(nlogn)

// Approach 2: Max heap
// Create Max heap for first k elements in the array and run loop for rest of elements:
// if element < heap.top, then pop the element in heap and insert current element in heap.

#include <iostream>
#include <queue>

using namespace std;

// Time:O(k+(n-k)logk);          Space:O(logk)

int kthSmallest(int arr[], int n, int k)
{

    priority_queue<int> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top(); // elements which are not in heap must be greater than or equal to top elemnet of heap and elemnets in the heap must be smaller than or equal to top elements.
}

int main()
{
    return 0;
}