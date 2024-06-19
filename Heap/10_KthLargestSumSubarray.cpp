#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// A subarray is the sequence of consecutive elements of the array

// Approach 1: Find sum of all subarrays using 2 nested for loops ans store it in ans vector.Sort this vector and return the kth element from the last. O(N^2) +O(N^2 Logn) = O(N^2 logN)

// Time Complexity: O(N^2 logN)  Space:O(N^2)
int getKthLargest(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> sumStore;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }

    sort(sumStore.begin(), sumStore.end());
    int size = sumStore.size();
    return sumStore[size - k];

    // sort(sumStore.begin(), sumStore.end(), greater<int>());

    // return sumStore[k - 1]
}

// Appraoch 2: Use heap to save space

// Time Complexity: O(N^2 logN)  Space:O(K)
int getKthLargest(vector<int> &arr, int k)
{
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> sumStore; // minHeap

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sumStore.size() == k)
            {
                if (sum > sumStore.top()) // store kth maxima
                {
                    sumStore.pop();
                    sumStore.push(sum);
                }
            }
            else
            {
                sumStore.push(sum);
            }
        }
    }

    return sumStore.top();
}

int main()
{

    return 0;
}