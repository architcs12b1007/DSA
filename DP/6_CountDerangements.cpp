#include<iostream>
#include<vector>
#define MOD 1000000007
using namespace std;


// Derangements is a permutation of 'N' elements such that no element appears its original position.

// given a number 'N', find the total number of Derangements possible of a set of 'N' elements

// N=3, {0,1,2}

// F(n)=(n-1)(F(n-1)+F(n-2))

// Time Complexity: O(2^n), Space Complexity:O(N)
long long int countDerangements(int n){
    
    if(n==1)
    return 0;
    if(n==2)
    return 1;
    
    return ((n - 1) % MOD * (countDerangements(n - 1) % MOD + countDerangements(n - 2) % MOD) % MOD) % MOD;

}

// Recursion with Memoization

long long int solveMemo(int n, vector<long long int> &dp){
    
    if(n==1)
    return 0;

    if(n==2)
    return 1;

    if(dp[n]!=-1)
    return dp[n];
    
    dp[n]=((n - 1) % MOD * (solveMemo(n - 1, dp) % MOD + solveMemo(n - 2,dp) % MOD) % MOD) % MOD;
    return dp[n];
}

// Tabulation, Space Optimization can be applied on this

long long int solveTab(int n){
    
    vector<int> dp(n+1);

    dp[1]=0;
    dp[2]=1;
    
    for(int i=3;i<=n;i++){
        dp[i]=((i - 1) % MOD * (dp[i-1] % MOD + dp[i-2] % MOD) % MOD) % MOD;
    }
    
    return dp[n];
}



int main(){

    return 0;
}

// 2nd Problem: Number of Ways to Wear Different Hats to Each Other