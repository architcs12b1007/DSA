#include <iostream>

using namespace std;

// Check whether n is a power of 2 or not
// An integer n is a power of two, if there exists an integer x such that n == 2^x.

// Approach: In its binary form, only one time high bits exists if it is power of 2.
bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;

    int count = 0;

    while (n != 0)
    {
        int bit = n & 1;
        if (bit)
        {
            count++;
            if (count >= 2)
                return false;
        }
        n = n >> 1;
    }

    if (count == 1)
        return true;
    else
        return false;
}

// Approach2: Time Complexity:O(1), Space:O(1)
bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;

    return ((n & (n - 1)) == 0);
}

int main()
{

    return 0;
}