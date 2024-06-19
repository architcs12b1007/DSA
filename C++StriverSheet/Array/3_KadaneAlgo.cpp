#include <iostream>
#include <vector>

using namespace std;

// Sum of subarrays(containing alteast one number) that has max sum (Subarray: should be contiguous)

// Approach 1: Make 2 nested loops and check for all subarrays and then return maximum.Time:O(N2) Space:O(1)
// Approach 2: Not to consider the subarray as a part of the answer if its sum is less than 0. 
// A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.
// Time:O(N), Space:O(1)

int maxSubArray(vector<int> &nums)
{
    int ans = INT_MIN, sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        if (sum > ans)
        {
            ans = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }
}

int main()
{
    return 0;
}