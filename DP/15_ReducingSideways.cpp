#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int solveRec(vector<int>& satisfaction, int index, int time){
    
    if(index>=satisfaction.size()){ // if(index==satisfaction.size())
        return 0;
    }

    int include=(satisfaction[index]*time)+solveRec(satisfaction,index+1, time+1);
    int exclude=solveRec(satisfaction,index+1, time);

    return max(include,exclude);
}

int solveMem(vector<int>& satisfaction, int index, int time,vector<vector<int>> &dp){
    
    if(index>=satisfaction.size()){
        return 0;
    }
    if(dp[index][time]!=-1)
    return dp[index][time];

    int include=(satisfaction[index]*(1+time))+solveMem(satisfaction,index+1, time+1,dp);
    int exclude=solveMem(satisfaction,index+1, time, dp);

    dp[index][time]= max(include,exclude);

    return dp[index][time];
}

// Tabulation: Time :O(N2) Space:O(N2)
int solveTab(vector<int>& satisfaction){
    sort(satisfaction.begin(),satisfaction.end());
    int n=satisfaction.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int index=n-1;index>=0;index--){
        for(int time=index;time>=0;time--){
            int include=(satisfaction[index]*(1+time))+dp[index+1][time+1];
            int exclude=dp[index+1][time];

            dp[index][time]= max(include,exclude);
        }
    }

    return dp[0][0];
}

// Space Optimization: Space Complexity:O(N), can be solved by 1 vector instead of 2 vector

// can be solved in O(1) space by using GREEDY APPROACH (Homework)
int solveSO(vector<int>& satisfaction){
    sort(satisfaction.begin(),satisfaction.end());
    int n=satisfaction.size();
    vector<int> curr(n+1,0),next(n+1,0);
    for(int index=n-1;index>=0;index--){
        for(int time=index;time>=0;time--){
            int include=(satisfaction[index]*(1+time))+next[time+1];
            int exclude=next[time];

            curr[time]= max(include,exclude);
        }
        next=curr;
    }

    return next[0];
}


int maxSatisfaction(vector<int>& satisfaction){
    // Recursion
    sort(satisfaction.begin(),satisfaction.end());
    int index=0, time=0;
    return solveRec(satisfaction, index, time);

    // Solve Mem
    int n=satisfaction.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

    return solveMem(satisfaction,index,time,dp);
}

int main(){

    vector<int> v{-1,-8,0,5,-9};
    cout<<maxSatisfaction(v)<<endl;;
    cout<<solveTab(v)<<endl;
    return 0;
}