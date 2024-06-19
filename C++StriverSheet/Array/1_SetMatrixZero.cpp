#include <iostream>
#include <vector>
using namespace std;

//  Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix. n: rows and m: cols

//Approach 1"


// Time Complezity: O(N^2)  Space Complexity:O(1)
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
    bool firstRow = 0, firstCol = 0;

    if (matrix[0][0] == 0)
    {
        firstRow = 1;
        firstCol = 1;
    }

    for (int i = 1; i < m; i++) // col
    {
        if (matrix[0][i] == 0)
        {
            firstRow = 1;
        }
    }

    for (int i = 1; i < n; i++) // row
    {
        if (matrix[i][0] == 0)
        {
            firstCol = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = INT_MAX;
                matrix[0][j] = INT_MAX;
            }
        }
    }

    for (int i = 1; i < m; i++) // col
    {
        if (matrix[0][i] == INT_MAX)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++) // row
    {
        if (matrix[i][0] == INT_MAX)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstRow)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[0][i] = 0;
        }
    }

    if (firstCol)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}
int main()
{
    return 0;
}