#include <iostream>
#include <limits.h>

using namespace std;
// so works for both +ve and -ve numbers
// it it goes outside signed 32 bit integer value, then return 0.

// Time Complexity:O(log(N))
int reverseInteger(int n)
{
    int ans = 0;

    while (n != 0)
    {
        int digit = n % 10; // gives remainder for number: -1234 is -4.
        // check 32 bit range if r is outside the range then return 0

        if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10))
            return 0;

        // if(ans > INT_MAX/10 || ans == INT_MAX/10 && digit > 7){ (in case of 10 digit number: last digit is 1or 2)
        //     return 0 ;
        // }

        // if(ans < INT_MIN/10 || ans == INT_MIN/10 && digit < -8){
        //     return 0 ;
        // }

        ans = (ans * 10) + digit;

        n = n / 10;
    }

    return ans;
}

int main()
{
    cout << reverseInteger(47412) << endl;

    return 0;
}