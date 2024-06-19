#include <iostream>
#include <queue>

using namespace std;

// N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.

// arr[] = {4, 3, 2, 6}  Output:29

// 1)2+3=5 {4, 5, 6} 2) 4+5=9 {9, 6}.  3) 9+6 =15
// 5 + 9 + 15 = 29.

// Approach:Lengths of the ropes which are picked first are included more than once in the total cost. Therefore, the idea is to connect the smallest two ropes first and recur for the remaining ropes

// Time Complexity: O(nlogn); Space Complexity:O(N)

long long minCost(long long arr[], long long n)
{

    priority_queue<long long, vector<long long>, greater<long long>> pq; // min heap

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    long long ans = 0;

    while (pq.size() > 1)
    {
        long long a = pq.top();
        pq.pop();

        long long b = pq.top();
        pq.pop();

        long long sum = a + b;
        pq.push(sum);
        ans += sum;
    }

    return ans;
}

int main()
{
    return 0;
}