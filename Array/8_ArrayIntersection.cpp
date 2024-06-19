#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// arr1={1,2,2,2,3,4} arr2={2,2,3,3} , o/p:2,2,3

// For ARRAYS NOT SORTED
// Time:O(N), Space:O(N)
vector<int> findArrayIntersection(vector<int> &arr1, vector<int> &arr2)
{
    unordered_map<int, int> freq;
    int size1 = arr1.size();
    int size2 = arr2.size();
    vector<int> ans;

    for (int i = 0; i < size1; i++)
    {
        freq[arr1[i]]++;
    }

    for (int i = 0; i < size2; i++)
    {
        if (freq.count(arr2[i]))
        {
            if (freq[arr2[i]] > 0)
            {
                ans.push_back(arr2[i]);
                freq[arr2[i]]--;
            }
        }
    }

    return ans;
}

// For ARRAYS SORTED
// Time:O(max(N,M)), Space:O(1)
vector<int> findArrayIntersection(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> ans;
    int n = arr1.size();
    int m = arr2.size();
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    return ans;
}

int main()
{

    return 0;
}