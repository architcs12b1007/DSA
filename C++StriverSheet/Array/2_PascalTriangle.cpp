#include <iostream>
#include <vector>

using namespace std;

// Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle. Solution: It is given by NCr (N!/(r)!(N-r)!) in O(1) time

// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

// Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle. 1<=N<=30

// Variation 3: Space Com
vector<vector<int>> pascalTriangle(int N)
{
    vector<vector<int>> ans(N);
    ans[0].push_back(1);

    if (N > 1)
    {
        ans[1].push_back(1);
        ans[1].push_back(1);
    }

    for (int i = 2; i < N; i++)
    {
        ans[i].push_back(1);
        for (int j = 1; j < i; j++)
        {
            int temp = ans[i - 1][j - 1] + ans[i - 1][j];
            ans[i].push_back(temp);
        }
        ans[i].push_back(1);
    }

    return ans;
}

int main()
{
    return 0;
}