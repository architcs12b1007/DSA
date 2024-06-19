#include<iostream>
#include<vector>
using namespace std;


void solveRec(vector<int> &nums,int index, int sum,int &maxi){

    if(index>nums.size()){
        maxi=max(maxi,sum);
        return;
    }

    solveRec(nums,index+2,sum+nums[index],maxi);
    solveRec(nums,index+1,sum,maxi);
}

// index can be passed (n-1) instead of 0 ==> we are traverse from right to left
// still gives the same answer (but in this index is subtract to (index-1) OR (index-2))

int solveRec1(vector<int> &nums,int index){

    if(index>nums.size()){
        return 0;
    }

    int include=nums[index]+solveRec1(nums,index+2);
    int exclude=solveRec1(nums,index+1);

    return max(include,exclude);
}

// Memoization: Time: O(N), Space complexity:O(N)
int solveMemo(vector<int> &nums,int index, vector<int> dp){

    if(index>nums.size()){
        return 0;
    }

    if(dp[index]!=-1)
    return dp[index];

    int include=nums[index]+solveRec1(nums,index+2);
    int exclude=solveRec1(nums,index+1);

    dp[index]=max(include,exclude);

    return dp[index];
}

// Tabulation (Space Optimization is possible here --> Space Complexity:O(1))
// Time Complexity: O(N), Space complexity:O(N)
int solveTab(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,INT_MIN);

    dp[0]=nums[0];

    for(int i=1;i<n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }

    return dp[n-1];
}


int maximumNonAdjacentSum(vector<int> &nums){

    // Recursion
    int maxi=INT_MIN,sum=0;
    solveRec(nums,0,sum,maxi);
    return maxi;

    return solveRec1(nums,0);

    // Recursion with Memoization
    int n=nums.size();

    vector<int> dp(n,-1);
    return solveMemo(nums,0,dp);

    // Tabulation
    return solveTab(nums);



}

int main(){

    return 0;
}