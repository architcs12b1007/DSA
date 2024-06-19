#include<iostream>
#include <math.h>
using namespace std;

long long calculate(long long p,
                    long long q)
{
    long long mod = 998244353, expo;
    expo = mod - 2;
 
    // Loop to find the value
    // until the expo is not zero
    while (expo) {
 
        // Multiply p with q
        // if expo is odd
        if (expo & 1) {
            p = (p * q) % mod;
        }
        q = (q * q) % mod;
 
        // Reduce the value of
        // expo by 2
        expo >>= 1;
    }
    return p;
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);   
}

int main(){
    int a=30;
    int b=9;
    int c=gcd(a,b);

    cout<<c<<endl;

    cout<<calculate(a/c,b/c)<<endl;

    cout<<pow(2,10)<<endl;

    int d='c'-'a';
    cout<<d<<endl;
    return 0;
}