#include <iostream>
#include <vector>
using namespace std;

// i/p: sorted and rotated array is given
// i/p: [7,9,1,2,3]      output: 1  {1 is minimum}
// {9,1} can be pivot element but depend on question we have to give answer

// Find min & max in sorted and rotated array ==> Need to find pivot element.

// Approach 1: Find minima in the array. Time:O(N)
// Arrpoach 2: Make mid logic either by comappring with arr[0] or arr[n-1]
int pivotElementIndex(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;

    if (start < end)
    {

        int mid = start + (end - start) / 2;

        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return start;
}

int main()
{

    return 0;
}