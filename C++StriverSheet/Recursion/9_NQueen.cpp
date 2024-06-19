#include <bits/stdc++.h>
using namespace std;
// Placing n queens on n × n chessboard such that no two queens can attack each other. Given an integer n, return all distinct solutions to the n -queens puzzle.

// Input: n = 4

// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]] where ‘Q’ and ‘.’ indicate queen and empty space respectively. output[R1,R2,R3,R4]

// Time Complexity: O(N!*N). For the first row, we check ‘N’ columns, for the second row we check 'N - 1 column and so on. hence time complexity will be N * (N-1) * (N-2) …. i.e N!
// {N is for checking issafe}

// Space Complexity: O(N^2) {for using 2-d board}
bool isSafe(vector<string> &board, int row, int col, int n)
{

    // left row check
    for (int i = 0; i <= col; i++)
    {
        if (board[row][i] == 'Q')
            return false;
    }

    int r = row;
    int c = col;

    // upper diagonal check

    while (r >= 0 && c >= 0)
    {
        if (board[r][c] == 'Q')
            return false;
        r--;
        c--;
    }

    r = row;
    c = col;

    // lower diagonal check

    while (r < n && c >= 0)
    {
        if (board[r][c] == 'Q')
            return false;
        r++;
        c--;
    }

    return true;
}
void solve(vector<vector<string>> &ans, vector<string> &board, int n, int col)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 'Q';
            solve(ans, board, n, 1 + col);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;

    vector<string> board;

    string s(n, '.');

    for (int i = 0; i < n; i++)
    {
        board.push_back(s);
    }
    solve(ans, board, n, 0);
    return ans;
}

// Optimized Approach: We can reduce the time complexity of issafe function from O(N) to O(1) by use hashing.
// we will use hashing to maintain a list to check whether that position can be the right one or not.
// leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
// (row+col) is constant and unique for each lowerdiagonal (0<= range<=14) {n=8}
// (row-col) is constant and unique for each upperdiagonal (-7<=range<=7) (so add n-1) where n=8

// Time:O(N!), Space:O(N) {Auxillary Space}

void solve1(vector<vector<string>> &ans, vector<string> &board, int n, int col, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 &&
            lowerDiagonal[(row + col)] == 0 &&
            upperDiagonal[(col - row + n - 1)] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[(row + col)] = 1;
            upperDiagonal[(col - row + n - 1)] = 1;
            solve1(ans, board, n, 1 + col, leftRow, lowerDiagonal, upperDiagonal);
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[(row + col)] = 0;
            upperDiagonal[(row + col + n - 1)] = 0;
        }
    }
}

vector<vector<string>> solveNQueens1(int n)
{
    vector<vector<string>> ans;

    vector<string> board;

    string s(n, '.');

    for (int i = 0; i < n; i++)
    {
        board.push_back(s);
    }
    vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    solve1(ans, board, n, 0, leftRow, upperDiagonal, lowerDiagonal);
    return ans;
}

int main()
{
    solveNQueens(4);

    return 0;
}