#include <iostream>
#include <vector>

using namespace std;

// You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i]. {SAME INDEX}

// Return the minimum number of needed operations to make nums1 and nums2 STRICTLY INCREASING. The test cases are generated so that the given input always makes it possible

// Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
// Output: 1 {swap nums1[3] with nums2[3]}
int solve(vector<int> &nums1, vector<int> &nums2, int i, int j)
{
    if (i < 1 || j < 1)
        return 0;

    if (nums1[i - 1] >= nums1[i] || nums1[j - 1] >= nums1[j])
    {
        // swap(nums1[i], nums2[j]);
        return 1 + solve(nums1, nums2, i - 1, j - 1);
    }
    else
    {
        return solve(nums1, nums2, i - 1, j - 1);
    }
}
int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int index1 = n - 1, index2 = n - 1;

    return solve(nums1, nums2, index1, index2);
}
int main()
{

    return 0;
}