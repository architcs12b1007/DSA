#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Need to find all distinct triplets present in thr array.
// Approach 1: Try all Triplets and count them

// Arrpoach2: Sort the array and then use 2 pointer approach;
// Time Complexity:O(N2), Space:O(logn)(for merge sort)
vector<vector<int>> findTriplets(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;
    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        int sum = target - arr[i];
        int start = i + 1, end = size - 1;
        while (start < end)
        {
            int add = arr[start] + arr[end];
            if (add == sum)
            {
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[start]);
                temp.push_back(arr[end]);
                ans.push_back(temp);
                while ((start + 1) < size && arr[start] == arr[start + 1])
                    start++;

                while ((end - 1) >= 0 && arr[end] == arr[end - 1])
                    end--;

                while (i + 1 < size && arr[i] == arr[i + 1])
                    i++;

                start++;
                end--;
            }
            else if (add < sum)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}