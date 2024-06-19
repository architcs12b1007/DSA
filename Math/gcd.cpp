#include<iostream>
#include<vector>
using namespace std;

// sieve of eratosthenes:Efficient way to find all primes smaller than n when n is smaller than 10 million 

// Count Prime numbers smaller than n

// Approach: Mark every no as prime number and then mark non-prime whoever comes in the table.

// Time Complexity: O(n/2 + n/3 + n/5 + n/7 + n/11------)
// O(n(1/2 + 1/3 + 1/5 + 1/7 + 1/9)) ==> HP of prime numnubers.[Taylor series]
// Time Complexity: O(n*loglog(n)), Space Complexity: O(N) ; can work for n=10^8 

int countPrimes(int n){
    int count=0;
    vector<bool> prime(n+1,true);

    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            count++;
            for(int j=i*i;j<n;j+=i)
            prime[j]=false;
        }
    }

    // for(int i=2;i<=n;i++){
    //     if(prime[i]){
    //         count++;
    //         for(int j=i*2;j<n;j+=i)
    //         prime[j]=false;
    //     }
    // }

    return count;
}

// Above method is NOT good for large values of n. So go for Segmented Sieve
// SEGMENTED SIEVE:The idea of a segmented sieve is to divide the range [0..n-1] in different segments and compute primes in all segments one by one

// Time Complexity:O(nlog(sqrt(n))) Space Complexity:O(sqrt(n)), can work for n=10^12




// GCD/HCF : Euclidean Algo- gcd(a,b)=gcd(a-b,b) / gcd(a,b)=gcd(a%b,b)

int gcd(int a, int b){
    if(a=0)
    return b;
    
    if(b=0)
    return a;

    while(a!=b){
        if(a<b){
            b=b-a;
        }else{
            a=a-b;
        }
    }

    return a;

}

int gcd1(int a, int b){
     return b==0?a:gcd(b,a%b);
}
// Fast Power: Modular Arihtmetics


// Fast exponential: a^b: if (b is even) (a^b/2)^2 else (a^b/2)^2 * a 

// a^b Time:O(b)

int power1(int a, int b){
    int ans=1;

    for(int i=0;i<b;i++){
        ans=ans*a;
    }

    return ans;
}

// Modular Exponentiation (x^n)%m  Time Complexity: O(logn)

int modularExponentiation(int x, int n,int m){

    int ans=1;

    while(n>0){
        if(n&1){

        }
        else{
            ans=ans*x
        }

        n=n/2;
    }

    return ans;
    
}


int main(){

    return 0;
}