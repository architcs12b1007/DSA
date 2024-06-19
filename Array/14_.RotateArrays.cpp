#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &nums, int start, int end)
{

    while (start < end)
    {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

// rotate the array to the right by k steps, where k is non-negative.

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]

// Approach 1: Two nested loop approach, Just rotate the entire array one position right and do it for k times.Time:O(N*k), Space:O(1)

// Approach 2:Take another vector and store the result after k positions in that vector.v[(i+k)%size]=arr[i], Time:O(N), Space O(N)

void rotate(vector<int> &nums, int k)
{
    int size = nums.size();
    vector<int> temp(size);

    for (int i = 0; i < size; i++)
    {
        temp[(i + k) % size] = nums[i];
    }

    // for (int i = 0; i < size; i++)
    // {
    //     nums[i] = temp[i];
    // }
    nums = temp;
}

// Appraoch 3:Can also be done 1)Reversing last k elements (right left) (reverse initial k elements:Left Shift)
// 2)Reversing first n-k-1 posiiotns.
// 3)Reversing enire array

// Time:O(N), Space:O(1)

void rotate(vector<int> &nums, int k)
{
    int size = nums.size();
    k = k % size;
    if (k == 0)
        return;

    reverse(nums, 0, size - 1);

    reverse(nums, 0, k - 1);

    reverse(nums, k, size - 1);
}
int main()
{

    return 0;
}