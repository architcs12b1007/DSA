#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// find the length of Longest (strictly) increasing subsequence.

int solveRec(int a[], int n, int index, vector<int>& result){
    if(index>=n){
        return result.size();
    }
    
    int include=INT_MIN; // include=0;
    if((!result.empty() && result.back()<a[index])|| index==0){
        result.push_back(a[index]);
        include=solveRec(a,n,index+1,result);
        result.pop_back();
    }

    int exclude= solveRec(a,n,index+1,result);

    return max(include,exclude);
}

int solve(int a[], int n, int index, int prev){
    if(index==n){
        return 0;
    }
    int include=0;
    if(prev==-1 || a[index]>a[prev]){
        include=1+solve(a,n,index+1,index);
    }
    int exclude=solve(a,n,index+1,prev);

    return max(include,exclude);
}

// Time Complexity:O(N2), Space:O(N2)
int solveMem(int a[], int n, int index, int prev, vector<vector<int>> &dp){
    if(index==n){
        return 0;
    }
    if(dp[index][prev+1]!=-1)
    return dp[index][prev+1];

    int include=0;
    if(prev==-1 || a[index]>a[prev]){
        include=1+solveMem(a,n,index+1,index,dp);
    }
    int exclude=solveMem(a,n,index+1,prev,dp);

    dp[index][prev+1]=max(include,exclude);

    return dp[index][prev+1];
}


// Time Complexity:O(N2), Space:O(N2)
int solveTab(int a[], int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int index=n-1;index>=0;index--){
        for(int prev=index-1;prev>=-1;prev--){ // prev is always less than index
            int include=0;
            if(prev==-1 || a[index]>a[prev]){
                include=1+dp[index+1][index+1];// here prev to 1+prev
            }
            int exclude=dp[index+1][prev+1];
            dp[index][prev+1]=max(include,exclude);
        }
    }
    
    return dp[0][0];
}

// Time Complexity:O(N2), Space:O(N)
int solveSpaceOptimization(int a[], int n){
    vector<int> curr(n+1,0);
    vector<int> next(n+1,0);
    
    for(int index=n-1;index>=0;index--){
        for(int prev=index-1;prev>=-1;prev--){ // prev is always less than index
            int include=0;
            if(prev==-1 || a[index]>a[prev]){
                include=1+next[index+1];// here prev to 1+prev
            }
            int exclude=next[prev+1];
            curr[prev+1]=max(include,exclude);
        }
        next=curr;
    }
    
    return next[0];
}

// DP with Binary Search: Time Complexity:O(n logn), Space Complexity:O(n)

int solveBS(int n, int a[]){

    if(n==0)
    return 0;
    vector<int> temp;

    temp.push_back(a[0]);

    for(int i=1;i<n;i++){
        if(a[i]>temp.back()){
            temp.push_back(a[i]);
        }
        else{
            // first element in the range [first, last) which has a value not less than val
            int index=lower_bound(temp.begin(),temp.end(),a[i])-temp.begin();// binary search lower bound
            a[index]=a[i];
        }
    }

    return temp.size();
}

int longestSubsequence(int n, int a[]){
    int index=0;
   // vector<int> result;

   // return solveRec(a,n,index,result);

    int prev=-1;
    return solve(a,n,index,prev);

    // Recursion with memoization

    vector<vector<int>> dp(n,vector<int>(n+1,-1));// index goes from o to n-1, curr goes from -1 to n-1;
    return solveMem(a,n,index,prev,dp);
}
int main(){
    int a[]={5,8,3,7,9,1};
    int n=sizeof(a)/sizeof(a[0]);

    cout<<longestSubsequence(n,a)<<endl;
    cout<<solveBS(n,a)<<endl;

    return 0;
}

// Applications: Russian Envelope Doll

// envelopes[i] = [wi, hi] represents the width and the height of an envelope.

// One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
// (rotation of envelope is NOT allowed)
// Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

// Approach: Sort envelopes on basis of width in increasing order and if width equal, sort height in
// decreasing order.[pick the envelope with greatest height in case of equal width as same width envelopee can not be taken]

// Now do Longest increaing Subsequence on height column (i.e.) will give ans.