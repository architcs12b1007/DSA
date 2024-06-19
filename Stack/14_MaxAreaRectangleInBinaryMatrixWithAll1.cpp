#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    stack<pair<int, int>> s;
    int ans = 0;
    int n = heights.size();

    vector<int> nextSmaller(n); // to store indices fro each height
    vector<int> prevSmaller(n); // to store indices fro each height

    s.push({-1, -1}); // 1st to store element and 2nd to store index {-1 is left to o index}

    for (int i = 0; i < n; i++)
    {

        while (heights[i] <= s.top().first)
        {
            s.pop();
        }
        prevSmaller[i] = s.top().second; // Can also be done with stack<int> to store indices and acccess element using arr[s.top()]
        s.push({heights[i], i});
    }

    while (!s.empty())
    {
        s.pop();
    }

    s.push({-1, n}); // {n is right to n-1 index}

    for (int i = n - 1; i >= 0; i--)
    {

        while (heights[i] <= s.top().first)
        {
            s.pop();
        }
        nextSmaller[i] = s.top().second;
        s.push({heights[i], i});
    }

    for (int i = 0; i < n; i++)
    {
        int area = heights[i] * (nextSmaller[i] - prevSmaller[i] - 1);
        ans = max(area, ans);
    }

    return ans;
}

// Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

// n = 4, m = 4
// M[][] = {{0 1 1 0},
//          {1 1 1 1},
//          {1 1 1 1},
//          {1 1 0 0}}
// Output: 8

// Approach: 1)Consider each row as the base of the histogram chart formed with all 1s.
// 2)For each row, increase height of a bar by the amount of the previous row, only if the value in current row is 1 and calculate the largest rectangular area of that histogram.
// 3)The largest rectangular area of a histogram among all possible base rows is the required are of the rectangle.

// Time Complexity:O(M*N) Space Complexity:(M)
int maxArea(vector<vector<int>> M, int n, int m) // n rows m cols
{
    vector<int> temp(m, 0); // no need to this, if i compute area for 1st row and then loop 1 to n-1 & update M[i][j]
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 1)
                temp[j] += M[i][j]; // M[i][j]+=M[i-1][j]
            else
                temp[j] = 0;
        }

        int area = largestRectangleArea(temp);
        ans = max(area, ans);
    }

    return ans;
}

int main()
{

    return 0;
}