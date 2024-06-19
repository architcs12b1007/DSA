#include <iostream>
#include <vector>
using namespace std;

// move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Time:O(N), Space:O(1)
// Need 2 traversal of loop
void moveZeroes(vector<int> &nums)
{

    int start = 0;
    int size = nums.size();

    for (int i = 0; i < size; i++)
    {
        if (nums[i] != 0)
        {
            nums[start] = nums[i];
            start++;
        }
    }

    while (start < size)
    {
        nums[start] = 0;
        start++;
    }
}

// Need only 1 traversal of loop
// Apprach: Just shift all Non-ZERO elemets on the left side
void moveZeroes1(vector<int> &nums)
{

    int start = 0;
    int end = 0;
    int size = nums.size();

    while (end < size)
    {
        if (nums[end] != 0)
        {
            swap(nums[start], nums[end]);
            end++;
            start++;
        }
        else
        {
            end++;
        }
    }
}

int main()
{

    return 0;
}