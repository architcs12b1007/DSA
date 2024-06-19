#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// n vertices and m edges. vertices labelled from 1 to N. Undirected graph. Output: YES/NO
// There are NO Parallel edges b/w two veritces.
// NO self loops in the graph

// Approach: Use BFS and parent array and  nbd node should not be parent of my curr node

string bfs(vector<vector<int>> &graph, vector<bool> &visited, int src)
{
    queue<int> q;
    unordered_map<int, int> parent;

    q.push(src);
    visited[src] = 1;
    parent[src] = -1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto &nbd : graph[curr])
        {
            if (visited[nbd] && parent[curr] != nbd) // nbd node should not be parent of my curr node
                return "Yes";
            if (!visited[nbd])
            {
                visited[nbd] = 1;
                parent[nbd] = curr;
                q.push(nbd);
            }
        }
    }
    return "No";
}

// Time Complexity:O(V+E)  Space Complexity:O(V+E)
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    vector<vector<int>> graph(n);
    vector<bool> visited(n, 0);
    string ans;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0] - 1; // 1 -indexing of vertices
        int v = edges[i][1] - 1;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = bfs(graph, visited, i);
            if (ans == "Yes")
                return ans;
        }
    }

    return "No";
}

int main()
{

    return 0;
}
