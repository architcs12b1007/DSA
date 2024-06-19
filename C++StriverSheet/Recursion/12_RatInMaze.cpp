#include <bits/stdc++.h>
using namespace std;

// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N – 1, N – 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are ‘U'(up), ‘D'(down), ‘L’ (left), ‘R’ (right).

// Value 0 in cell: BLOCKED
// Value 1 in cell: CAN TRAVEL

// Note: In a path, no cell can be visited more than one time.
// If the source cell is 0, the rat cannot move to any other cell.

// Print the answer in lexicographical(sorted) order

// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1},
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output: DDRDRR DRDDRR

void solve(vector<vector<int>> &m, vector<string> &ans, string path, int i, int j, int n, vector<vector<bool>> &visited)
{

    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(path);
    }

    if (i > 0 && !visited[i - 1][j] && m[i - 1][j] == 1)
    {
        visited[i][j] = 1;
        solve(m, ans, path + 'U', i - 1, j, n, visited);
        visited[i][j] = 0;
    }

    if (i < n - 1 && !visited[i + 1][j] && m[i + 1][j] == 1)
    {
        visited[i][j] = 1;
        solve(m, ans, path + 'D', i + 1, j, n, visited);
        visited[i][j] = 0;
    }

    if (j > 0 && !visited[i][j - 1] && m[i][j - 1] == 1)
    {
        visited[i][j] = 1;
        solve(m, ans, path + 'L', i, j - 1, n, visited);
        visited[i][j] = 0;
    }

    if (j < n && !visited[i][j + 1] && m[i][j + 1] == 1)
    {
        visited[i][j] = 1;
        solve(m, ans, path + 'R', i, j + 1, n, visited);
        visited[i][j] = 0;
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;

    if (m[0][0] = 0 || m[n - 1][n - 1] == 0)
        return ans;

    string path = "";
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    solve(m, ans, path, 0, 0, n, visited);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}