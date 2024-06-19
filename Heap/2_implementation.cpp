// Heap is a data structure (complete binary tree) that comes with a heap order property(Max/Min Heap)

// Binary Tree: each nodes has atmost 2 children.

// Complete Binary Tree: -every level is completely filled except the last level

// -node always added from the left (lean towards the left) (All the leaf elements must lean towards the left)

// A full binary tree is a binary tree in which all of the nodes have either 0 or 2 offspring

// Heap: Max Heap & Min Heap

// A max heap is a complete binary tree in which the value of a node is greater than or equal to the values of its children

// Approach: implement in from of 1-index array: ith node-> 2*i left child & 2*i+1 right child
// parent of ith node: i/2 (floor value)

// 0-based indexing- ith node: 2*i+1 left child & 2*i+2 right child; parent:(i-1)/2;

#include <iostream>
// #include <algorithm>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        size = 0;
        arr[0] = -1;
    }

    // insertion in max heap. Time Complexity: O(logn)
    // Approach: Insert element at the end & take the last element to its correct position.

    void insert(int val)
    {

        size += 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // deletion in max heap.(delete root node) Time Complexity:O(logn)
    // Approach: Swap first node with last node, remove last node and then propogate root node to its correct position

    void deletefromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }
        else
        {
            int i = 1;
            arr[i] = arr[size]; // put last value of array at root postion
            size--;

            while (i < size)
            {
                int left = i * 2, right = i * 2 + 1;
                int swapIndex = i;

                // pick greater child elements & swap it
                if (left <= size && arr[swapIndex] < arr[left])
                {
                    swapIndex = left;
                }

                if (right <= size && arr[swapIndex] < arr[right])
                {
                    swapIndex = right;
                }

                if (i != swapIndex)
                {
                    swap(arr[i], arr[swapIndex]);
                    i = swapIndex;
                }
                else
                {
                    return;
                }
            }
        }
    }
};

int main()
{

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    // h.insert(100);
    h.print();
    return 0;
}