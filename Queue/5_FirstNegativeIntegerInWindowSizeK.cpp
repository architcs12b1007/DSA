#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//  find the first negative integer for each and every window(contiguous subarray) of size K.
// If there is no -ve in that window, print 0.

// Approach: Use queue and store only negative elements and return its top when moving window of size K.
// Why queue?? bcoz i need only FIRST -ve element
// Time Complexity:O(N)  Space Complexity:O(K)

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    queue<long long> q;
    vector<long long> ans;

    for (int i = 0; i < K - 1; i++)
    {
        if (A[i] <= 0)
        {
            q.push(A[i]);
        }
    }

    int start = 0;
    int end = K - 1;

    while (end < N)
    {
        if (A[end] < 0)
        {
            q.push(A[end]);
        }

        if (q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            int top = q.front();

            if (top == A[start])
            {
                q.pop();
            }
            ans.push_back(top);
        }

        start++;
        end++;
    }

    return ans;
}

// Approach: We need to track always first-ve index and check whether it is current window or not.
// Opitimized Approach: Time Complexity:O(N),  Space Complexity:O(1)

vector<long long> printFirstNegativeInteger1(long long int A[],
                                             long long int N, long long int K)
{

    int firstNegativeIndex = 0;
    vector<long long> ans;

    for (int i = K - 1; i < N; i++)
    {
        // do increment when out of window and positive elements
        while ((firstNegativeIndex < i) && (firstNegativeIndex <= i - K || A[firstNegativeIndex] >= 0))
        {
            firstNegativeIndex++;
        }

        if (A[firstNegativeIndex] < 0)
        {
            ans.push_back(A[firstNegativeIndex]);
        }
        else
        {
            ans.push_back(0);
        }
    }

    return ans;
}

int main()
{

    return 0;
}