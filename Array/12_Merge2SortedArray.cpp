#include <iostream>
#include <vector>
using namespace std;

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Example 1:

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Time Complexity:O(m+n) Space:O(1)
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    int size1 = m - 1;
    int size2 = n - 1;
    int end = m + n - 1;
    while (size1 >= 0 && size2 >= 0)
    {
        if (nums1[size1] >= nums2[size2])
        {
            nums1[end] = nums1[size1];
            size1--;
            end--;
        }
        else
        {
            nums1[end] = nums2[size2];
            size2--;
            end--;
        }
    }

    while (size2 >= 0)
    {
        nums1[end] = nums2[size2];
        size2--;
        end--;
    }
}

int main()
{

    return 0;
}