#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Input: nums = [3,4,5,1,2]
// Output: true

// Approach 1:Brute force and check if it is possible for a sorted array to start from each position

// Approach2: Only 1 decreasing consecutive pair. Alo check for end & start position comparisions

// Time Complexity:O(N), Space Complexity:O(1)

bool check(vector<int> &nums)
{
    int decreasingCount = 0;
    int size = nums.size();

    for (int i = 1; i < size; i++)
    {
        if (nums[i] < nums[(i - 1)])
        {
            decreasingCount++;
        }
    }

    if (nums[size - 1] > nums[0])
        decreasingCount++;

    return decreasingCount <= 1; // it is 0 for arr={1,1,1,1}
}

int main()
{

    return 0;
}