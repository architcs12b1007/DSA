#include <iostream>
#include <vector>

using namespace std;
// Array os size N having values between 1 and N-1 atleast once.There is single element that is present twice.Need to find duplicate integer value

// Appraoch: Need to cancel all elements from 1 to N-1, so take xor for all elements from1 to N-1 & then take xor with respect to all elements of array
// Time:O(N), Space:O(1)

int findDuplicate(vector<int> &arr)
{
    int ans = 0;
    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            ans = ans ^ arr[i];
        }
        else
        {
            ans = ans ^ arr[i] ^ (i + 1);
        }
    }

    return ans;
}

// ANOTHER QUESTION:

// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

// // Approach:We Can Use That Given Array As an Frequency Array
// and instead of Count for each Element, we can Use -[minus] To track Each element in the array we are traverse Or Not [as They said That any element can occoure max Twice]
// While Traverseing if We Get Negetive element again, We Know That It's Allredy Visited So It Wolud Be a duplicate num <= Push That Into ANS array

// Lastly Return ANS array

// Time:O(N), Space:O(1)

vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> ans;

    int size = nums.size();

    for (int i = 0; i < size; i++)
    {
        if (nums[abs(nums[i]) - 1] < 0)
        {
            ans.push_back(abs(nums[i]));
        }
        else
        {
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
    }

    return ans;
}

int main()
{

    return 0;
}