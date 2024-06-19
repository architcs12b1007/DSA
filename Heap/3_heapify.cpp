// Heapify Algorithm: Covert binary tree(represented in form of array 1-indexed) to HEAP

// Array (1-index) of size n. Leaf node ranges from ((n/2) + 1) to n
// Array (0-index) of size n. Leaf node ranges from ((n/2)) to n

// Approach: Leaf node is alreay heap, so need not to process them.But put the nodes fron n/2 to 1 to its correct position according to min/max heap.

// O(log n) time complexity.

#include <iostream>
#include <algorithm>

using namespace std;

// Use 1-index array

void heapify(int arr[], int n, int index)
{
    int largest = index;

    int leftIndex = 2 * largest, rightIndex = 2 * largest + 1;

    if (leftIndex <= n && arr[largest] < arr[leftIndex])
        largest = leftIndex;

    if (rightIndex <= n && arr[largest] < arr[rightIndex])
        largest = rightIndex;

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    }
}

// O(n) time complexity for building a binary heap. (Check proof on GFG)
void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
}

int main()
{
    return 0;
}