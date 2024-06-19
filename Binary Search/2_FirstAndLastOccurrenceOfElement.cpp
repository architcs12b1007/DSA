#include <iostream>
#include <vector>
using namespace std;
// return first and last occurences of element k in array. if nothing is present, return -1, -1

// i/P:[0,1,1,2]  o/p:1 2

// Time Complexity:O(1og N)  Space:O(1)
int binarySearchFirstAndLastPosition(vector<int> &arr, int k, bool pos)
{
    int start = 0;
    int end = arr.size() - 1;

    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == k)
        {
            ans = mid;    // store ans as well whnever element if found in each casr
            if (pos == 0) // 1st occcurence: search on left space
                end = mid - 1;
            else
                start = mid + 1; // last occurence: search on right spcae
        }
        else if (arr[mid] > k)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    pair<int, int> ans;

    ans.first = binarySearchFirstAndLastPosition(arr, k, 0);
    ans.second = binarySearchFirstAndLastPosition(arr, k, 1);

    return ans;
}

int main()
{

    return 0;
}

// Applications:
// Find total no of occurrences of element k in sorted array. (LastOccurIndex -FirstOccurIndex + 1)