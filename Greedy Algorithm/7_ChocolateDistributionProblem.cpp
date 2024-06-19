#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. There are M students, the task is to distribute chocolate packets among M students such that :
// 1. Each student gets exactly one packet.
// 2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.  (M<=N)

// Time Complexity:O(log N) Space:O(1)

long long findMinDiff(vector<long long> a, long long n, long long m)
{

    sort(a.begin(), a.end());

    long long ans = INT_MAX;

    for (int i = m - 1; i < n; i++)
    { // check in each window of size m

        ans = min(ans, a[i] - a[i - m + 1]);
    }

    return ans;
}

int main()
{

    return 0;
}