#include <bits/stdc++.h>
using namespace std;
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

// Time Complexity:O(N!*N)
void solve(vector<int> &nums, int index, vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[i], nums[index]);

        solve(nums, index + 1, ans); // next call to (index+1) instead of (i+1)
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    solve(nums, 0, ans);
    return ans;
}

int main()
{

    return 0;
}