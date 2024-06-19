#include<iostream>
#include<vector>
using namespace std;

// Similar Problem like 2_Min Number Of Coins

// Array of distict integers, target is given. find no of different ways selectimg element form the array
// such that sum of chosen elements is equal to target

// input:{1,2} target=3 ; output: 3 {(1,1,1), (1,2), (2,1)}

int solveRec(vector<int> &nums,int target){
    if(target==0)
    return 1;
    if(target<0)
    return 0;

    int ans=0;

    for(int i=0;i<nums.size();i++){
        ans+=solveRec(nums, target-nums[i]);
    }

    return ans;
}

// Recursion with Memoization
int solveMemo(vector<int> &nums,int target, vector<int> &dp){
    if(target==0)
    return 1;
    if(target<0)
    return 0;
    
    if(dp[target!=-1])
    return dp[target];

    int ans=0;

    for(int i=0;i<nums.size();i++){
        ans+=solveRec(nums, target-nums[i]);
    }
    dp[target]=ans;
    return dp[target];
}


// Tabulation
int solveMemo(vector<int> &nums,int target){
    vector<int> dp(target+1,0);
    dp[0]=1;
    
    // traversing from target 1 to tar
    for(int i=1;i<=target;i++){
        for(int j=0;j<nums.size();j++){
            if(i-nums[j]>=0)
            dp[i]+=dp[i-nums[j]];
    }

    }
    
    return dp[target];
}
int findWays(vector<int> &num, int target){
    // Recursion
    return solveRec(num,target);

    // Recursion with Memoization
    vector<int> dp(target+1,-1);
    return solveMemo(num,target,dp);
}

int main(){

    return 0;
}