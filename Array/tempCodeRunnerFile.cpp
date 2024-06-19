#include <iostream>
#include <math.h>
using namespace std;

// Approach 1: 1)Divide n by 2 ans store the remainder in my ans.2)Repeat until n does not equal to 0.  3)Reverse the ans

// Arrpoach 2: if num&1 is 1 then num is odd, else it is even.
// store bit using bit=n&1, and then shift n by right shift operator n=n>>1 (divide by 2)
// Repeat this until n does not equal to 0;

int DecimalToBinary(int n)
{
    int ans = 0;
    int index = 0;
    while (n != 0)
    {
        bool bit = n & 1;
        if (bit)
            ans = ans + pow(10, index);
        cout << n << "  " << ans << "  " << pow(10, index) << endl;
        n = n >> 1;
        index++;
    }

    return ans;
}

int main()
{

    cout << DecimalToBinary(16) << endl;
    cout << DecimalToBinary(20) << endl;
    return 0;
}