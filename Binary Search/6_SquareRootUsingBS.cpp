#include <iostream>
#include <vector>
using namespace std;

// Square root of an integer.         0 <= n <= 10 ^ 9
// n=27  ouput=5;  n=100, output=10

// Approach 1: Brute force: Start from 1 and iterating it by 1 and check whether its square is less than or equal to N. Time Complexity:O(sqrt(N))

// Approach2: We have a binary search space 1 to N. We keep half our search space on each iteration and on mid we check where we have to go: left search space or right search space.
// why this search space? My ans lies b/w 1 to N

// Time Complexity: O(log N)
int sqrt(int n)
{
    int start = 1;
    int end = n;
    int ans = 0; // for n==0;

    while (start <= end)
    {
        long long mid = start + (end - start) / 2;
        long long squareNum = mid * mid;
        if (squareNum <= n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

// No need to us long long data type
int sqrt1(int n)
{
    int start = 1;
    int end = n;
    int ans = 0; // for n==0;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (mid <= n / mid)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

// if need to find suare root with precision, then find it by bruteforce logic

double squareRootPrecision(int n, int precisionUnits)
{
    int num = sqrt(n);
    double ans = num;
    double factor = 1;

    for (int i = 1; i <= precisionUnits; i++) // no of precision digits
    {
        factor = factor / 10;
        for (double j = ans; j * j <= n; j += factor)
        {
            ans = j;
        }
    }

    return ans;
}

int main()
{
    // cout << squareRootPrecision(2, 3) << endl;
    cout << squareRootPrecision(3, 8) << endl;

    // cout << squareRootPrecision(2, 10) << endl;

    return 0;
}