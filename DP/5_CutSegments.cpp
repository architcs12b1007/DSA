#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// n: denote length of rod, determine MAXIMUM no of segments you can make of this rod provided that each segment should be of length 'X', 'Y' and 'Z'.

// n=7, (5,2,2) output=2
// n=8, (3,3,3) ouput=0 (no way to cut of length 3)

int solveRec(int n,int x, int y, int z){
    if(n==0)
    return 0;
    if(n<0)
    return INT_MIN;

    int a=solveRec(n-x,x,y,z);
    int b=solveRec(n-y,x,y,z);
    int c=solveRec(n-z,x,y,z);
    int ans=max(a,max(b,c))+1;

    return ans;


}

// Recursion with Memoization
int solveMemo(int n,int x, int y, int z,vector<int> &dp){
    if(n==0)
    return 0;
    if(n<0)
    return INT_MIN;

    if(dp[n]!=1)
    return dp[n];

    int a=solveMemo(n-x,x,y,z,dp);
    int b=solveMemo(n-y,x,y,z,dp);
    int c=solveMemo(n-z,x,y,z,dp);
    dp[n]=max(a,max(b,c))+1;

    return dp[n];
}

// Tabulation: dp[i]: ith length rod ke maximum no of segments
// Space Optimization is NOT possible
int solveTab(int n,int x,int y,int z){
    vector<int> dp(n+1,INT_MIN);//vector<int> dp(n+1,-1;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        if((i-x)>=0)//if((i-x)>=0 && dp[i-x]!=-1)
        dp[i]=max(dp[i],dp[i-x]+1);
        if((i-y)>=0)//if((i-y)>=0 && dp[i-y]!=-1)
        dp[i]=max(dp[i],dp[i-y]+1);
        if((i-y)>=0)//if((i-z)>=0 && dp[i-z]!=-1)
        dp[i]=max(dp[i],dp[i-z]+1);
    }
    if(dp[n]<0)
    return 0;
    else
    return dp[n];
} 

int cutSegments(int n,int x, int y, int z){

    // Recursion
    int ans=solveRec(n,x,y,z);
    if(ans<0)
    return 0;
    else
    return ans;

    // Recursion with Memoization
    vector<int> dp(n+1,-1);
    int ans=solveMemo(n,x,y,z,dp);
    if(ans<0)
    return 0;
    else
    return ans;


}

int main(){

    int n,x,y,z;
    cin>>n>>x>>y>>z;
    cout<<cutSegments(n,x,y,z)<<endl;

    return 0;
}