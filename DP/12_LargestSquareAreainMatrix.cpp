#include<iostream>
#include<vector>

using namespace std;

// given binary martix of size n*m
// find max-size square submatrix with all 1s

int solveRec(vector<vector<int>> mat, int i, int j, int &maxi){
    if(i>=mat.size() || j>=mat[0].size())
    return 0;

    int right=solveRec(mat,i,j+1,maxi);
    int bottom=solveRec(mat,i+1,j,maxi);
    int diagonal=solveRec(mat,i+1,j+1,maxi);
    if(mat[i][j]==1){
        int ans=1+min(right,min(bottom,diagonal));
        maxi=max(ans,maxi);
        return ans;
    }
    else{
        return 0;
    }
}

// Recursion with Memoization
int solveMemo(vector<vector<int>> mat, int i, int j, int &maxi,vector<vector<int>> &dp){
    if(i>=mat.size() || j>=mat[0].size())
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    int right=solveMemo(mat,i,j+1,maxi,dp);
    int bottom=solveMemo(mat,i+1,j,maxi,dp);
    int diagonal=solveMemo(mat,i+1,j+1,maxi,dp);
    
    if(mat[i][j]==1){
        dp[i][j]=1+min(right,min(bottom,diagonal));
        maxi=max(dp[i][j],maxi);
        return dp[i][j];
    }
    else{
        return dp[i][j]=0;
    }
}

// Tabulation, T.C:O(N), S.C.:O(N)

int solveTab(vector<vector<int>> mat, int n, int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int maxi=0;

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int right=dp[i][j+1];
            int bottom=dp[i+1][j];
            int diagonal=dp[i+1][j+1];
            
            if(mat[i][j]==1){
                dp[i][j]=1+min(right,min(bottom,diagonal));
                maxi=max(dp[i][j],maxi);
            }else{
                dp[i][j]=0;
            }
        }
    }
    return maxi;
}

// Space Optimization: done in O(m), [can also be done in O(1): It is based on just making the given matrix as a dp memory.]

int solveSpaceOptimization(vector<vector<int>> mat, int n, int m){
    vector<int> prev(m+1,0);
    vector<int> curr(m+1,0);
    int maxi=0;

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int right=curr[j+1];
            int bottom=prev[j];
            int diagonal=prev[j+1];
            
            if(mat[i][j]==1){
                curr[j]=1+min(right,min(bottom,diagonal));
                maxi=max(curr[j],maxi);
            }else{
                curr[j]=0;
            }
        }
        prev=curr;
    }
    return maxi;
}

int maxSquare(int n,int m,vector<vector<int>> mat){

    // Recursion
    int maxi=0;
    solveRec(mat,0,0,maxi);
    return maxi;

    // Recursion with memoization;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    solveMemo(mat,0,0,maxi,dp);
    return maxi;

}

int main(){

    return 0;
}