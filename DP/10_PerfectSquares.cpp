#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

// Similar to Coin and Combination Sum IV Problem
// Given number N. Find min no of squares of any no that leads to N.

// i/p: N=100 Output=1  (10*10 ; 5*5+5*5+5*5+5*5)
// i/p: N=6 Output:3  (1*1+1*1+2*2)
int solveRec(int n){
    if(n==0)
    return 0;
    
    int mini=n;// n is tha max value it can take
    for(int i=1;i*i<=n;i++){
        int ans=solveRec(n-(i*i));
        mini=min(mini,1+ans);
        
    }

    return mini;
}

// Recursion with memoization
int solveMemo(int n, vector<int> &dp){
    if(n==0)
    return 0;

    if(dp[n]!=-1)
    return dp[n];
    
    int mini=n;// n is tha max value it can take
    for(int i=1;i*i<=n;i++){
        int ans=solveMemo(n-(i*i),dp);
        mini=min(mini,1+ans);
        
    }
    dp[n]=mini;
    return dp[n];
}

// Tabulation: Time Complexity:O(N*N^1/2) Space Complexity:O(N)

int solveTab(int n){

    vector<int> dp(n+1,n);// initialize with max possible values
    dp[0]=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=i;j++){
            dp[i]=min(dp[i],dp[i-(j*j)]+1);
        }
    }
    return dp[n];
}

int MinSquares(int n){
    //return solveRec(n);

    // Recursion with Memoization
    // vector<int> dp(n+1,-1);
    // return solveMemo(n,dp);

    // Tabulation
    return solveTab(n);

}


int main(){
    cout<<MinSquares(100)<<endl;
    cout<<MinSquares(6)<<endl;

    return 0;
}