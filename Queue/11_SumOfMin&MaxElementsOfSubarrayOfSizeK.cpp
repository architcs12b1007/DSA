#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.

// Approach 1: Nested Loop, Check for each element and then in another loop find max, min in window of size k and then store sum. Time Complexity:O(N*K)

// Approach 2: 1)K size dequeue: maxi- elements stored in decreasing order (front gives maxi elements)
// 2) K size dequeue: mini- elements stored in increasing order (front gives mini elements)

// Time Complexity: O(N)  Space Complexity:O(K)
int SumKSubarray(vector<int> arr, int k)
{
    deque<int> maxi, mini;
    int sum = 0;
    int n = arr.size();
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }

        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    for (int i = k; i < n; i++)
    {
        sum += maxi.front() + mini.front();

        // deletion logic (remove all elemnts that are outside of this window)

        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }

        while (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }

        // addition logic
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }

        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    sum += maxi.front() + mini.front();

    return sum;
}
int main()
{

    return 0;
}