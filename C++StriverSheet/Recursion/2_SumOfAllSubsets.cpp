#include <bits/stdc++.h>
using namespace std;

// Given an array print all the sum of the subset generated from it, in the increasing order.

// Time Complexity:O(2^N + 2^N log(2^N)) {2^N log(2^N) for sorting}
void sumofAllSubsets(vector<int> v, int index, int sum, vector<int> &ans)
{
    if (index == v.size())
    {
        ans.push_back(sum);
        return;
    }

    sumofAllSubsets(v, index + 1, sum + v[index], ans); // element is picked
    sumofAllSubsets(v, index + 1, sum, ans);            // element is not picked
}

int main()
{
    vector<int> v = {1, 2, 3};
    int sum = 0;
    vector<int> ans;

    sumofAllSubsets(v, 0, sum, ans);

    sort(ans.begin(), ans.end());

    for (auto &a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}