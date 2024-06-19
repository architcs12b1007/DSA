#include<iostream>
#include<vector>
using namespace std;

// N items and ith item has weight wi and value vi
// Thief can carry max weight W into his knapsack
// Need to find the maximum value that a thief can generate by stealing items.

// Approach: Try all combination of weight (using include & exclude logic) & find max weight
// moving from right to left
int solveRec(vector<int> &weight,vector<int> &value, int index, int capacity){
    // base case
    // if only 1 item to steal, then just compare its weight with the knapsack capacity
    if(index==0){
        if(weight[index]<=capacity)
        return value[index];
    }
    else{
        return 0;
    }

    int include=0;

    if(weight[index]<=capacity)
    include=value[index]+solveRec(weight,value,index-1,capacity-weight[index]);
    
    int exclude=solveRec(weight,value,index-1,capacity);

    return max(include,exclude);
}

int solveMemo(vector<int> &weight,vector<int> &value, int index, int capacity,vector<vector<int>> &dp){
    // base case
    // if only 1 item to steal, then just compare its weight with the knapsack capacity
    if(index==0){
        if(weight[index]<=capacity)
        return value[index];
    }
    else{
        return 0;
    }

    if(dp[index][capacity]!=-1)
    return dp[index][capacity];

    int include=0;

    if(weight[index]<=capacity)
    include=value[index]+solveMemo(weight,value,index-1,capacity-weight[index],dp);
    
    int exclude=solveMemo(weight,value,index-1,capacity,dp);

    dp[index][capacity]=max(include,exclude);
    return dp[index][capacity];

}

int solveTab(vector<int> &weight,vector<int> &value, int n, int capacity){
    
    // step 1
    vector<vector<int>> dp(n,vector<int>(capacity+1,0));

    // step 2:Analyse Basecase
    for(int w=weight[0];w<=capacity;w++){
        if(weight[0]<=capacity){
            dp[0][w]=value[0];
        }
        else{
            dp[0][w]=0;
        }
    }

    // step 3: take care of remaining recursive calls
    for(int index=1;index<n;index++){
        for(int w=0;w<=capacity;w++){
            int include=0;
            
            if(weight[index]<=w)
            include=value[index]+dp[index-1][w-weight[index]];
            
            int exclude=dp[index-1][w];
            
            dp[index][w]=max(include,exclude);

        }
    }

    return dp[n-1][capacity];
    

}


// space optimization can be possible

// Time Complexity O(n*Maxweight); Space Complexity:O(MaxWeight)

int solveTab(vector<int> &weight,vector<int> &value, int n, int capacity){
    
    // step 1
    vector<int> dp(capacity+1,0);

    // step 2:Analyse Basecase
    for(int w=weight[0];w<=capacity;w++){
        if(weight[0]<=capacity){
            dp[w]=value[0];
        }
        else{
            dp[w]=0;
        }
    }

    // step 3: take care of remaining recursive calls
    for(int index=1;index<n;index++){
        vector<int> temp(capacity+1,0);
        for(int w=0;w<=capacity;w++){
            int include=0;
            
            if(weight[index]<=w)
            include=value[index]+dp[w-weight[index]];
            
            int exclude=dp[w];
            
            temp[w]=max(include,exclude);

        }
        dp=temp;
    }

    return dp[capacity];
    

}

// can i optimized it futher??
// Yes, it depennds on previous value, so wa can use one array instead of two and start computation
// from backwards (right to left)

int solveTab(vector<int> &weight,vector<int> &value, int n, int capacity){
    
    // step 1
    vector<int> dp(capacity+1,0);

    // step 2:Analyse Basecase
    for(int w=weight[0];w<=capacity;w++){
        if(weight[0]<=capacity){
            dp[w]=value[0];
        }
        else{
            dp[w]=0;
        }
    }

    // step 3: take care of remaining recursive calls
    for(int index=1;index<n;index++){
        for(int w=capacity;w>=0;w--){
            int include=0;
            
            if(weight[index]<=w)
            include=value[index]+dp[w-weight[index]];
            
            int exclude=dp[w];
            
            dp[w]=max(include,exclude);

        }
    }

    return dp[capacity];
    

}

int knapsack(vector<int> weight,vector<int> value, int n, int maxWeight){

    // Recursion
    return solveRec(weight,value,n-1,maxWeight);

    // Recursion with memoization
    vector<vector<int>> dp(n,vector<int>(maxWeight,-1));
    return solveMemo(weight,value,n-1,maxWeight,dp);

}

int main(){

    return 0;
}

// Applications:
// Equal Subset Sum Partition 
// Subset Sum 
// Min Subset Sum Difference 
// Count of Subset Sum 
// Target Sum 
