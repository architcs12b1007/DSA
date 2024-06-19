#include <bits/stdc++.h>
using namespace std;

// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may ONLY BE USED ONCE in the combination.

// Note: The solution set must not contain duplicate combinations

// Input: candidates = [2,5,2,1,2], target = 5
// Output: [ [1,2,2], [5]]

// Time Complexity: O(2^N * k)
void solve(vector<int> &candidates, int target, int index, vector<vector<int>> &ans, vector<int> &temp)
{
    if (target < 0)
    {
        return;
    }
    if (target == 0)
    {
        ans.push_back(temp); // Time: O(K) where K is average length of every subset
        return;
    }

    for (int i = index; i < candidates.size(); i++)
    {
        if (i != index && candidates[i] == candidates[i - 1])
        {
            continue;
        }
        temp.push_back(candidates[i]);
        solve(candidates, target - candidates[i], i + 1, ans, temp);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    solve(candidates, target, 0, ans, temp);
    return ans;
}

int main()
{

    return 0;
}