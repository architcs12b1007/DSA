#include<iostream>
#include<vector>
using namespace std;
// Minimum elements (Min number of Coins)

// Total no of elements you have to take to reach target sum 'X'
// You have an infinite number of elements of each type

// i/p=[1,2,3] X=7 O/p:3
// i/p=[1] X=0 O/p:0 (No Coin required)
// i/p=[2] X=3 O/p:-1 (Not possible)

int solveRec(vector<int> &num, int x){
    if(x==0){
        return 0;
    }else if(x<0){
        return INT_MAX;
    }

    int mini=INT_MAX;
    for(int i=0;i<num.size();i++){
        int ans=solveRec(num,x-num[i]);
        if(ans!=INT_MAX){
            mini=min(mini,ans+1);// adding 1 here, so put INT_MAX condition, otherwise overflow error
        }
    }
    return mini;

}

// Time Complexity:O(No of coins*x), x is target amount ; Space Complexity:O(x)
int solveMemo(vector<int> &num, int x, vector<int> &dp){
    if(x==0){
        return 0;
    }else if(x<0){
        return INT_MAX;
    }

    if(dp[x]!=-1)
    return dp[x];

    int mini=INT_MAX;
    for(int i=0;i<num.size();i++){
        int ans =solveMemo(num,x-num[i],dp);
        if(mini!=INT_MAX){
            mini=min(mini,ans+1);
        }
    }

    dp[x]=mini;
    return mini;

}
// dp[i]: min no of coins required to make target i.
int solveTab(vector<int> &num, int x){

    vector<int> dp(x+1,INT_MAX);
    dp[0]=0;

    // trying to solve for every amount from 1 to x
    for(int i=1;i<=x;i++){
        for(int j=0;j<num.size();j++){
            if((i-num[j])>=0 && dp[i-num[j]!=INT_MAX]){
                dp[i]=min(dp[i-num[j]]+1,dp[i]);
            }
        }
    }

    if(dp[x]==INT_MAX)
    return -1;
    else
    return dp[x];

}

int minimumElements(vector<int> &num, int x){
    
    // Recursion
    int ans= solveRec(num,x);
    if(ans==INT_MAX)
    return -1;
    else
    return ans;

    // Recursion with Memoization

    vector<int> dp(x+1,-1);
    solveMemo(num,x,dp);
    if(dp[x]==INT_MAX)
    return -1;
    else
    return dp[x];

}


int main(){
    return 0;
}