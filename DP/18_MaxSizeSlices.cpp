#include <iostream>
#include <vector>

using namespace std;

// Same as HOUSE ROBBERS PROBLEM

// slices of size 3n is given where sizes of pizza are arranges in clockwise mananer
// you pick any slice of pizza, thwn you cannot pick next slice in clockwise direction as well as in anticlockwide direction.
// return max possible sum of slices that you can pick

int solveRec(vector<int> &slices, int n, int index, int endIndex){

    if(n==0 || index>endIndex){
        return 0;
    }

    int include=slices[index]+ solveRec(slices,n-1,index+2,endIndex);
    int exclude=solveRec(slices,n,index+1,endIndex);

    return max(include,exclude);
}


int solveMem(vector<int> &slices, int n, int index, int endIndex, vector<vector<int>> &dp){

    if(n==0 || index>endIndex){
        return 0;
    }
    if(dp[index][n]!=1)
    return dp[index][n];

    int include=slices[index]+ solveMem(slices,n-1,index+2,endIndex,dp);
    int exclude=solveMem(slices,n,index+1,endIndex,dp);

    dp[index][n]=max(include,exclude);

    return dp[index][n];
}

// Tabulation

int solveTab(vector<int> &slices){
    int k=slices.size();
    int n=k/3;

    vector<vector<int>> dp1(k,vector<int>(n+1,-1));
    vector<vector<int>> dp2(k,vector<int>(n+1,-1));

    // case 1
    for(int i=k-2;i>=0;i--){
        for(int j=1;j<=n;j++){
            int include=slices[i]+ dp1[i+2][j-1];
            int exclude=dp1[i+1][j];

            dp1[i][j]=max(include,exclude);
        }
    }

    // case 2

    for(int i=k-1;i>=1;i--){
        for(int j=1;j<=n;j++){
            int include=slices[i]+ dp2[i+2][j-1];
            int exclude=dp2[i+1][j];

            dp1[i][j]=max(include,exclude);
        }
    }

    return dp[0][n];

}


int maxSizeSlices(vector<int> &slices){

    int k=slices.size();
    
    int case1=solveRec(slices,k/3,0,k-2);
    int case2=solveRec(slices,k/3,1,k-1);

    return max(case1,case2);

    //Recursion with Memoization

    vector<vector<int>> dp1(k,vector<int>(k/3+1,-1));

    case1=solveMem(slices,k/3,0,k-2,dp1);

    vector<vector<int>> dp2(k,vector<int>(k/3+1,-1));
    case2=solveMem(slices,k/3,1,k-1,dp2);

    return max(case1,case2);
    

}

int main(){

    return 0;
}
