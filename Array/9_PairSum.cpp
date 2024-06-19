#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool sortcol(const vector<int> &v1, const vector<int> &v2)
{
    if (v1[0] == v2[0])
    {
        return v1[1] < v2[1];
    }
    return v1[0] < v2[0];
}

// Return list of all pairs such that sum of elements of each pair equal to s.

// Approach1: Nested loop and check for each pair.Time:O(N2) Space:O(1)
// Approach2: Sort the array and use 2 pointer approach (by putting pointers at start & end):TIme:O(N Log(N))

// Arrpoach2: Use unordered_set. Time:O(N), Space:O(1)

// [1,1,2,2,2] target=3,  [{1,2},{1,2},{1,2},{1,2},{1,2},{1,2}]

vector<vector<int>> pairSum(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    unordered_map<int, int> s;
    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        if (s.count(arr[i]))
        {
            vector<int> temp;
            int element = target - arr[i];
            int size = s[arr[i]];

            // Insert Pair in increasing order
            if (arr[i] > element)
            {
                temp.push_back(element);
                temp.push_back(arr[i]);
            }
            else
            {
                temp.push_back(arr[i]);
                temp.push_back(element);
            }
            for (int i = 0; i < size; i++)
                ans.push_back(temp);
        }
        s[target - arr[i]]++;
    }
    // no need to make sortcol function as by default it sort in increasing order.
    sort(ans.begin(), ans.end(), sortcol);

    return ans;
}

int main()
{

    return 0;
}