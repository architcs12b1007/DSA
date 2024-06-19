#include<iostream>
#include<vector>
using namespace std;

int solveRec(vector<int>& values,int i, int j){
    // Base case (when we have only 2 nodes,so cannot make a triangle)
    if(i+1==j)
    return 0;
    
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
        int ans=min(ans,(values[i]*values[j]*values[k])+solveRec(values,i,k)+solveRec(values,k,j));
    }
    return ans;
    
}

// Recusion with memoization

int solveMemo(vector<int>& values,int i, int j, vector<vector<int>> &dp){
    // Base case (when we have only 2 nodes,so cannot make a triangle)
    if(i+1==j)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];
    
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
        int ans=min(ans,(values[i]*values[j]*values[k])+solveRec(values,i,k)+solveRec(values,k,j));
    }
    dp[i][j]=ans;
    return dp[i][j];
    
}

// Tabulation

int solveTab(vector<int>& values){
    vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
    
    if(i+1==j)
    return 0;

 
    
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
        int ans=min(ans,(values[i]*values[j]*values[k])+solveRec(values,i,k)+solveRec(values,k,j));
    }
    dp[i][j]=ans;
    return dp[i][j];
    
}
int minScoreTriangulation(vector<int>& values){

    // Recursion
    int n=values.size();
    return solveRec(values,0,n-1);

    // Recursion with memoization
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return solveMemo(values,0,n-1,dp);



}

int main(){

    return 0;
}