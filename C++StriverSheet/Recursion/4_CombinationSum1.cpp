#include <bits/stdc++.h>
using namespace std;

// Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target.

// The same number may be chosen from candidates an UNLIMITED NUMBER OF TIMES. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// 1 <= target <= 40;  1 <= candidates.length <= 30;  2 <= candidates[i] <= 40

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]

// O(2^t * k) where t is the target, k is the average length

// Why not (2^n) but (2^t) (where n is the size of an array)?
// Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.

void solve(vector<vector<int>> &ans, int index, vector<int> &candidates, int target, vector<int> &temp)
{
    if (target < 0)
    {
        return;
    }
    if (target == 0)
    {
        ans.push_back(temp); // Time: O(K) where K is average length of every subset
    }

    for (int i = index; i < candidates.size(); i++)
    {
        temp.push_back(candidates[i]);
        solve(ans, i, candidates, target - candidates[i], temp);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve(ans, 0, candidates, target, temp);

    return ans;
}

int main()
{

    return 0;
}