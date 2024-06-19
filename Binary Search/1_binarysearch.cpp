#include <iostream>
#include <vector>
using namespace std;

// It applies only when element should be in Monotonic Functions

// {N,N/2,N/4,N/8,-----,N/2^k}  = N/2^k=1 = k=logN , where k no of iterations

// Recursion: Time Complexity:(O(logN)) Space Complexity:O(logn)
int binarysearch(int *arr, int s, int e, int key)
{

    if (s > e)
        return -1;

    int mid = s + (e - s) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] > key)
    {
        return binarysearch(arr, s, mid - 1, key);
    }
    else
    {
        return binarysearch(arr, mid + 1, e, key);
    }
}

// Iterative Solution
// Time Complexity:O(log n) Space:O(1)

int binarySearchIterative(vector<int> arr, int value)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == value)
        {
            return mid; // return index of found element
        }
        else if (arr[mid] > value)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1; // NOT FOUND
}

int main()
{
    int arr[] = {1, 2, 12, 14, 16, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    cin >> key;

    cout << binarysearch(arr, 0, n - 1, key);

    cout << "Thanks" << endl;

    return 0;
}

// Applications:

// Lowerbound , UpperBound  ===>(No. of occurences)
// Peak Element in Mountain Array
// Pivot element in roatated array
// Search in roated array
// Find answer by decreasing your Search Space (Aggregate cow, roti, paratha, book allocation, painter partition)