#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Given a Days array consisting of 'N' days (each day is an integer: 1<=i<=365)
// Train tickes are sold in 3 diff passes: 1-day, 7-day, 30 day passes [cost[0], cost[1], cost[2]]
// To find the MIN no of cost required to complete the tour.
int solveRec(int n, vector<int> &days, vector<int> &cost, int index){
    if(index>=n){
        return 0;
    }
    // 1 day pass
    int a=cost[0]+solveRec(n,days,cost,index+1);
    
    // 7 day pass
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);
    int b=cost[1]+solveRec(n,days,cost,i);

    // 30 day pass
    for(i=index;i<n && days[i]<days[index]+30;i++);
    int c=cost[2]+solveRec(n,days,cost,i);

    int ans= min(a,min(b,c));

    return ans;

}

int solveMemo(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp){
    if(index>=n){
        return 0;
    }
    if(dp[index]!=-1)
    return dp[index];
    // 1 day pass
    int a=cost[0]+solveMemo(n,days,cost,index+1,dp);
    
    // 7 day pass
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);
    int b=cost[1]+solveMemo(n,days,cost,i,dp);

    // 30 day pass
    for(i=index;i<n && days[i]<days[index]+30;i++);
    int c=cost[2]+solveMemo(n,days,cost,i,dp);

    dp[index]= min(a,min(b,c));

    return dp[index];

}

int solveTab(int n, vector<int> &days, vector<int> &cost, int index){
    vector<int> dp(n+1,INT_MAX);

    dp[n]=0;
    
    for(int k=n-1;k>=0;k--){
    // 1 day pass
    int a=cost[0]+dp[k+1];
    
    // 7 day pass
    int i;
    for(i=k;i<n && days[i]<days[k]+7;i++);
    int b=cost[1]+dp[i];

    // 30 day pass
    for(i=k;i<n && days[i]<days[k]+30;i++);
    int c=cost[2]+dp[i];

    dp[k]= min(a,min(b,c));

    }

    return dp[0];

}

// Space optimization: T.C:O(N), Space Complexity:O(1)

int solveSpaceOptimization(int n, vector<int> &days, vector<int> &cost, int index){
    int ans=0;
    queue<pair<int,int>> weekly, monthly; // (day, cost till that day)
    
    for(int i=0;i<n;i++){
        //step 1: remove expired days from queue

        while(weekly.size()>0 && weekly.front().first+7<=days[i])// !weekly.empty()
        weekly.pop();

        while(monthly.size()>0 && monthly.front().first+30<=days[i])// !monthly.empty()
        monthly.pop();
        //step 2: push current day's cost
        weekly.push(make_pair(days[i],ans+cost[1]));
        monthly.push(make_pair(days[i],ans+cost[2]));

        // step 3: ans update
        ans=min(ans+cost[0],min(weekly.front().second,monthly.front().second));
    }

    return ans;

}


int minimumCoins(int n, vector<int> days, vector<int> cost){
    // Recursion
    return solveRec(n,days,cost,0);

    // Recursion with memoization
    vector<int> dp(n+1,-1);
    return solveMemo(n,days,cost,0,dp);

}
int main(){

    return 0;
}