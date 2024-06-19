#include <bits/stdc++.h>
using namespace std;

// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.

// Time Complexity : O(9^t) , where t is empty cells
// Space Complexity: O(1)
bool isValid(vector<vector<char>> &board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == c)
            return false;

        if (board[i][col] == c)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool solve(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isValid(board, i, j, c))
                    {
                        board[i][j] = c;

                        if (solve(board))
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] = '.'; // need to bactrack when there is no
                        }
                    }
                }
                return false; // returning false when there is no possibility (all char 1 to 9 are exhaust)
            }
        }
    }

    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}

int main()
{

    return 0;
}