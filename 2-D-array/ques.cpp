#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

// How 2D stored in memory??
//  convert 2d array into 1 dimensional array (Take example of 3*3 2d array)
// Memory save in terms of 1 dimensional
// formula: C*i+j, where i(row), j(col) C:total no of columns 


// int a[3][3]={1,2,3,4,5,6,7,8,9}; (Takes element row wise)
// int a[3][3]={{1,2,3},{4,5,6},{7,8,9}}

// When passing a two-dimensional array to a function, you must specify the number of columns as a constant when you write the parameter type, so the compiler can pre-calculate the memory addresses of individual elements.

// Linear Search in 2-d array
bool isSearch(int arr[][3], int target, int row, int col){

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==target)
            return true;
        }
    }

    return false;

}

// Largest Row Sum and return its index. print the first column top to bottom, then bottom to top & so on.

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int nCols){
    
}

int LargestRowSul(int arr[][3],int row, int col){
    int maxi=INT_MIN,rowIndex;
    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<col;j++){
            sum+=arr[i][j];
        }
        if(maxi<sum){
            maxi=sum;
            rowIndex=i;
        }
    }

    return rowIndex;
}


// Print like a wave eg:first column print from top to bottom, next from bottom to top ans so on.

vector<int> printWave(vector<vector<int>> arr, int nRows, int mCols){

    vector<int> ans;

    for(int col=0;col<mCols;col++){
        if(col & 1){
            // odd Index: Bottom to Top if(col%1)
            for(int row=nRows-1;row>=0;row--){
                ans.push_back(arr[row][col]);
            }

        
        }
        else{
            // even index Top to bottom
            for(int row=0;row<nRows;row++){
                ans.push_back(arr[row][col]);
            }

        }
    }

    return ans;
}

// print matrix in spiral order

//Approach: Print Starting Row - Print Ending Column- Print Ending Row - Print Starting Column

vector<int> spiralOrder(vector<vector<int>> matrix){
    vector<int> ans;
    int row=matrix.size();
    int col=matrix[0].size();
    int size=row*col;
    int count=0;

    int SRowIndex=0, ERowIndex=row-1;
    int SColIndex=0, EColIndex=col-1;

    while(count<size){

        // print starting row

        for(int i=SColIndex;count<size && i<=EColIndex;i++){
            ans.push_back(matrix[SRowIndex][i]);
            count++;
        }
        SRowIndex++;


        // print ending col

        for(int i=SRowIndex;count<size && i<=ERowIndex;i++){
            ans.push_back(matrix[i][EColIndex]);
            count++;
        }
        EColIndex--;

        // print ending row

        for(int i=EColIndex;count<size && i>=SColIndex;i--){
            ans.push_back(matrix[ERowIndex][i]);
            count++;
        }
        ERowIndex--;

        // print starting col

        for(int i=ERowIndex;count<size && i>=SRowIndex;i--){
            ans.push_back(matrix[i][SColIndex]);
            count++;
        }
        SColIndex++;

    }

    return ans;

}


// Rotate a matrix (N*N) by 90 degrees clockwise (do it in place)

// 1 2 3           7 4 1
// 4 5 6  ====>    8 5 2
// 7 8 9           9 6 3

// First Transpose the matrix and then reverse each array(also called reflect in linear algebra)

void rotate(vector<vector<int>> matrix){

    int n= matrix.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }

}

// Rotate group of 4 cells, We can iterate over each group of four cells and rotate them.
void rotate1(vector<vector<int>> matrix){

    int n= matrix.size();

    for(int i=0;i<(n+1)/2;i++){
        for(int j=0;j<n/2;j++){
             int temp = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 -i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            
        }
    }

}

// Search in a 2D matrix (M*N)
// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.

// Approach: I can think of 2-d array in terms of 1-d array and 1-d array is in sorted order, so i can go for binary serach. Here Time Complexity O(log(mn))

bool searchMatrix(vector<vector<int>>& matrix ,int target){

    int start=0;
    int nRows=matrix.size();
    int nCols=matrix[0].size();
    int end=(nRows*nCols)-1;

    while(start<=end){
        int mid= start+(end-start)/2;
        
        //find row & col number in 2-d matric correponds to mid element in 1-d array (mid=C*i+j) 
        int row=mid/nCols,col=mid%nCols;
        if(matrix[row][col]==target)
        return true;
        else if(matrix[row][col]<target) 
        start=mid+1;
        else
        end=mid-1;

    }

    return false;

}

// Search in a 2 D matrix-2
// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

// Approach:Either start from Top Right Corner (Bottom Left corner) as elements in that row are smaller and elements in the colum are greater. 


// Time complexity : O(n+m)

// On every iteration (during which we do not return true) either row or col is
// is decremented/incremented exactly once. Because row can only be
// decremented m times and col can only be incremented n times
// before causing the while loop to terminate, the loop cannot run for
// more than m+n iterations.

bool searchMatrix2(vector<vector<int>>& matrix ,int target){
    int nRows=matrix.size();
    int nCols=matrix[0].size();

    int rowIndex=0,colIndex=nCols-1;

    while(rowIndex<nRows && colIndex>=0){
        if(matrix[rowIndex][colIndex]==target)
        return true;
        else if(matrix[rowIndex][colIndex]<target)
        rowIndex++;
        else
        colIndex--;
    }

    return false;

}

int main(){

    int a[3][3]={1,2,3,4,5,6,7,8,9}; 

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }



}