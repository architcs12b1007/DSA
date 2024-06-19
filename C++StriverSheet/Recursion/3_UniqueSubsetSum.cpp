#include <bits/stdc++.h>
using namespace std;

// Return all unique Subsets in any order (as array may contain duplicates) (Unique Power Set)

// Input: array[] = [1,2,2]

// Output: [ [],[1],[1,2],[1,2,2],[2],[2,2] ]  {Duplicates: [2],[1,2]}

// Approach: Generate all possible subsets (by using 2 options: pick or unpick);
// Use sets to discard duplication

// Time Complexity:(2^n*(klogx)), 2^n  for generating every subset and k* log( x)  to insert every combination of average length k in a set of size x.
// Space Complexity:O(2^n*k) {use set to store 2^n subsets of average length k}

void solve(vector<int> &nums, int index, vector<int> temp, vector<vector<int>> &ans, set<vector<int>> &s)
{
    if (index == nums.size())
    {
        sort(temp.begin(), temp.end());
        if (!s.count(temp))
        {
            s.insert(temp);
            ans.push_back(temp);
        }
        return;
    }
    temp.push_back(nums[index]);
    solve(nums, index + 1, temp, ans, s);
    temp.pop_back();
    solve(nums, index + 1, temp, ans, s);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    set<vector<int>> s;
    solve(nums, 0, temp, ans, s);
    return ans;
}

// Optimized solution: Initially start with an empty data structure. In the first recursion, call make a subset of size one, in the next recursion call a subset of size 2, and so on.

// First level of recursion: we have a list of empty size
// Second level of recursion: we have all subsets of size 1
// Third level of recursion: we have all subsets of size 2 and so on

// On new level of recursion, always pick the first element (since it is first of that kind)
// If duplicates occurs, only pick the first occuring element of that kind

// Time Complexity: O(2^N * k)
// Space Complexity: O(2^n * k) to store every subset of average length k

void solve1(vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, int index)
{
    ans.push_back(temp); // Time: O(K) where K is average length of every subset
    for (int i = index; i < nums.size(); i++)
    {
        if (i != index && nums[i] == nums[i - 1]) // (needs to take first occurence,whenever we start)
        {
            continue;
        }

        temp.push_back(nums[i]);
        solve1(nums, temp, ans, i + 1);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup1(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(nums.begin(), nums.end());
    solve1(nums, temp, ans, 0);
    return ans;
}

int main()
{
    vector<int> v = {1, 2, 2};
    vector<vector<int>> ans = subsetsWithDup1(v);
    for (auto a : ans)
    {
        for (auto b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }

    return 0;
}