#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Return a list of BFS starting from 0.THe traversal should proceed from left to right according to input adjacency list. n: number of vertices

// Approach: Make visited true when pusing vertices in queue and push vertices in ans when removing vertices from queue
// Time Complexity:O(V+E)  Space Complexity:O(V+E)
vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    vector<int> ans;
    vector<bool> visited(n, 0);

    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        visited[curr] = 1;
        ans.push_back(curr);

        for (auto &nbd : adj[curr])
        {
            if (!visited[nbd])
            {
                q.push(nbd);
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}
