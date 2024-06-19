#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int power1(int n, int index)
{
    int ans = 1;
    for (int i = 0; i < index; i++)
    {
        ans = ans * (n);
    }

    return ans;
}

// Approach 1: 1)Divide n by 2 ans store the remainder in my ans.2)Repeat until n does not equal to 0.  3)Reverse the ans

// Arrpoach 2: if num&1 is 1 then num is odd, else it is even.
// store bit using bit=n&1, and then shift n by right shift operator n=n>>1 (divide by 2)
// Repeat this until n does not equal to 0;

// Can also take int ans[32] or string to store ans in case of big numbers
int DecimalToBinary(int n)
{
    int ans = 0;
    int index = 0;

    while (n != 0)
    {
        int bit = n & 1; // n%2;
        if (bit)
            ans = ans + power1(10, index);

        n = n >> 1; // n=n/2;
        index++;
    }

    return ans;
}

string DecimalToBinary1(int n)
{
    string ans;
    int index = 0;

    while (n != 0)
    {
        int bit = n & 1; // n%2;
        ans.push_back(bit + '0');

        n = n >> 1; // n=n/2;
        index++;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    cout << DecimalToBinary1(1) << endl;
    cout << DecimalToBinary1(2) << endl;
    cout << DecimalToBinary1(4) << endl;
    cout << DecimalToBinary1(8) << endl;
    cout << DecimalToBinary1(12) << endl;
    return 0;
}

// We store negative numbers in 2's complement form:
// 2's complement for : 1's complement + 1

// For -ve numbers: -6(000110) (6 bits but in computer take 32 bits instead)
// Take 1's complement (111001)
// Add 1: (111010) -6 is stored  like this in computer

// Why? 2's complemnt: bcoz there is no ambiguity here to represent 0.