#include <iostream>
#include <math.h>
using namespace std;

// The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// 0<=n<=pow(10,9)

int bitwiseComplement(int n)
{
    if (n == 0)
        return 1;
    int index = 0;
    int ans = 0;
    while (n != 0)
    {
        int bit = n & 1;

        if (bit == 0)
        {
            ans = ans + pow(2, index);
        }
        n = n >> 1;
        index++;
    }
    return ans;
}

// Approach 2

int bitwiseComplement(int n)
{
    if (n == 0)
        return 1;

    int m = n;
    int mask = 0; // n=6(00110)  mask(00111) (mak bits high)
    while (m != 0)
    {
        m = m >> 1;
        mask = mask << 1;
        mask = mask | 1; // keep on adding 1 on right side
    }

    int negate = ~n; // negate=(11001)

    return (negate & mask); // (00001)
}
int main()
{

    return 0;
}