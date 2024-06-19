#include <iostream>
#include <vector>
using namespace std;

// Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].  arr.length>=3; there always exist some i

// arr = [0,10,5,2]
// Output: 1

// Approach 1: Traverse the array and find max index. Time:O(N)
// Approach 2: Mid element is always satisfy either 3 conditions: Lie on peak, increasing side, decreasing side.

// Time:O(log N)
int peakIndexInMountainArray(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;

    int ans = -1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid; // Why NOT mid-1 bcoz peak can also be at mid and this condition may shift my mid to increasing line
        }
    }

    return start;
}

// Do not thin in this way
int peakIndexInMountainArray1(vector<int> &arr)
{

    int start = 0;
    int end = arr.size() - 1;

    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid])
        {
            ans = mid;
            return ans;
        }
        else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
        {
            start = mid;
        }
        else
        {
            end = mid;
        }
    }

    return ans;
}
int main()
{

    return 0;
}