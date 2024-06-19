#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// cuboids[i] = [widthi, lengthi, heighti]

// You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj..You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

// Return the maximum height of the stacked cuboids

bool check(vector<int>& a, vector<int>& b){
    if(a[0]<=b[0] && a[1]<=b[1] && a[2]<=b[2])
    return true;
    else
    return false;
}

int solve(vector<vector<int>>& cuboids){
    int n=cuboids.size();
    vector<int> currRow(n+1,0), nextRow(n+1,0);

    for(int curr=n-1;curr>=0;curr--){
        for(int prev=curr-1;prev>=-1;prev--){
            int include=0;
            if(prev==-1 || check(cuboids[prev],cuboids[curr])){// condition changes in this
                include=cuboids[curr][2]+nextRow[curr+1];// height addition changes in this
            }
            int exclude=nextRow[prev+1];
            currRow[prev+1]=max(include,exclude);

        }
        nextRow=currRow;
    }
    return nextRow[0];

}

int maxHeight(vector<vector<int>>& cuboids){

    for(int i=0;i<cuboids.size();i++){
        // sort all dimensions of every cube 
        sort(cuboids[i].begin(),cuboids[i].end());
    }

    // sort all cubes based on width or length (last column represents height)
    sort(cuboids.begin(),cuboids.end());

    // use logic of LIS

    solve(cuboids);

}

int main(){

    return 0;
}