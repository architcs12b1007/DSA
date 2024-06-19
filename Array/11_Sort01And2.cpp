#include <iostream>

using namespace std;

// Approach 1: Take 3 counters for 0s,1s and 2s and count it in array and then update array value based on that. We need to traverse the entire loop twice.

// Arrpoach 2:Take 3 variables (low,mid, high) such that all values below low represent 0 and values above high represent 2.

// Time Complexity: O(N)

void sort012(int *arr, int n)
{
    int low = 0, mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{

    return 0;
}