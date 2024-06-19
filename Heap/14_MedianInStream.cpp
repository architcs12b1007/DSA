#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Find median of an element read so far; (Median of Stream of Running Integers)
// Median is middle value of an ordered integer list. In case of even, it is average of 2 middle values.

// i/p: [1 2 3]  o/p:[1,1,2]  0<data<10^8

// i/p: [5 3 8] o/p [5,4,5]

// Approach 1: Do Insertion Sort at each moving index. then we find array in O(1 time). But Sorting takes O(N^2) time complexity

// Approach 2: We will make sure size difference of two heap is max poosible by 1.
// Take 2 heaps: leftheap (MaxHeap)  & rightHeap (MinHeap), so 3 cases are possible:
// 1) Both have same size: median=leftheap.top()+rightHeap.top()/2
// 2)LeftHeap has size n-1 & right heap has size n: median=rightHeap.top()
// 3)LeftHeap has size n & right heap has size n-1: median=leftHeap.top();

// Time Complexity:O(N log N) Space Complexity:O(N)

vector<int> findMedian(vector<int> &arr, int n)
{
    vector<int> median;
    if (n == 1)
    {
        median.push_back(arr[0]);
        return median;
    }
    priority_queue<int> leftHeap;                             // maxHeap
    priority_queue<int, vector<int>, greater<int>> rightHeap; // minHeap

    if (arr[0] < arr[1])
    {
        leftHeap.push(arr[0]);
        rightHeap.push(arr[1]);
    }
    else
    {
        rightHeap.push(arr[0]);
        leftHeap.push(arr[1]);
    }

    median.push_back(arr[0]);
    median.push_back((arr[0] + arr[1]) / 2);

    for (int i = 2; i < n; i++)
    {
        int l = leftHeap.size();
        int r = rightHeap.size();

        if (l == r) // both heaps have same size
        {
            if (arr[i] > median[i - 1])
            {
                rightHeap.push(arr[i]);
                median.push_back(rightHeap.top());
            }
            else
            {
                leftHeap.push(arr[i]);
                median.push_back(leftHeap.top());
            }
        }
        else if (l < r) // right heap have same 1 size more
        {
            if (arr[i] > median[i - 1])
            {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(arr[i]);
                median.push_back((leftHeap.top() + rightHeap.top()) / 2);
            }
            else
            {
                leftHeap.push(arr[i]);
                median.push_back((leftHeap.top() + rightHeap.top()) / 2);
            }
        }
        else // left heap have same 1 size more
        {
            if (arr[i] > median[i-1])
            {
                rightHeap.push(arr[i]);
                median.push_back((leftHeap.top() + rightHeap.top()) / 2);
            }
            else
            {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(arr[i]);
                median.push_back((leftHeap.top() + rightHeap.top()) / 2);
            }
        }
    }

    return median;
}

int main()
{

    return 0;
}