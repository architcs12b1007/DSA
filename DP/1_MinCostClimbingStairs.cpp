#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007

// initially you are at 0th stair and you have to reach nth Stairs
// you can climb either 1 step or 2 step.


int solve(long long nStairs, int i){
    if(i==nStairs)
    return 1;
    else if(i>nStairs)
    return 0;

    return solve(nStairs,i+1)+solve(nStairs,i+2);
    
}

// F(n)=F(n+1)+F(n+2)
int countDistinctWayToClimbStairs1(long long nStairs){
    return solve(nStairs,0);
}

// F(n)=F(n-1)+F(n-2) (to reach nth stair, one should come either (n-1)th stair or (n-2)th stair)
int countDistinctWayToClimbStairs(long long nStairs){

    if(nStairs==1)
    return 1;

    if(nStairs==2)
    return 2;

    return countDistinctWayToClimbStairs(nStairs-1)+countDistinctWayToClimbStairs(nStairs-2);

}


// MIN COST CLIMBING STAIRS

// cost[i]-cost of ith step of a staircase; return min cost to reach at top floor {cost.length>=2}
// you can start from step with index 0 or index 1, you can climb either 1 or 2 steps

// F(n)= min(F(n-2), F(n-1)) + cost(n) (Min cost to reach nth floor)

int solve2(vector<int> &cost,int n, vector<int> &dp){
    if(n==0)
    return cost[0];
    
    if (n==1)
    return cost[1];

    if(dp[n]!=-1)
    return dp[n];

    dp[n]= min(solve2(cost,n-1,dp),solve2(cost,n-2,dp))+cost[n];
    return dp[n];
}

int minCostClimbingStairs(vector<int>& cost){

    // int n=cost.size();
    // // can be simplified more --> Homework (only (n-2) can be found, after that (n-1)th can be found easily)
    // int ans= min(solve(cost,n-1),solve(cost,n-2));
    // return ans;


    // // Recursion with memoization
    // int n=cost.size();
    // vector<int> dp(n+1,-1);
    // int ans= min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
    // return ans;


    // Tabulation

    // vector<int> dp(n+1,-1);
    // dp[0]=cost[0];
    // dp[1]=cost[1];
    // for(int i=2;i<cost.size();i++){
    //     dp[i]=min(dp[i-1],dp[i-2])+cost[i];
    // }
    // return min(dp[n],dp[n-1]);

    // Space Optimization

    int a=cost[0];
    int b=cost[1];
    for(int i=2;i<cost.size();i++){
        int temp=min(a,b)+cost[i];
        a=b;
        b=temp;
    }
    return min(a,b);



}

int main(){

    return 0;
}