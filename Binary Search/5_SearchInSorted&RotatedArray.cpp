#include <iostream>
#include <vector>
using namespace std;

// Find the index where elemernt k is present in sorted & rotated array.If k is not present, return -1

// [12,15,18,2,4] k=2  output:3 (index)

int pivotIndex(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] >= arr[0])
            start = mid + 1;
        else
            end = mid;
    }

    return start;
}

int binarySearch(vector<int> &arr, int s, int e, int k)
{
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] > k)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

// Time Complexity: O(log N)
int search(vector<int> &arr, int n, int k)
{
    // // 0 rotation and complete orted array is given
    // if (arr[0] <= arr[n - 1])
    // {
    //     return binarySearch(arr, 0, n - 1, k);
    // }

    int index = pivotIndex(arr);
    int ans = -1;
    if (k >= arr[0])
    {
        ans = binarySearch(arr, 0, index, k); // why not index-1?? bcoz in case of zero rotation, [1 2 3 4] , index will be at last postion
    }
    else
    {
        ans = binarySearch(arr, index, n - 1, k);
    }

    return ans;
}

// Try 2 other fiiferent solution
int main()
{

    return 0;
}