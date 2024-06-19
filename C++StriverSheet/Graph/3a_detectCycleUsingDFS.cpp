#include <iostream>
#include <vector>

using namespace std;

// n vertices and m edges. vertices labelled from 1 to N. Undirected graph. Output: YES/NO
// There are NO Parallel edges b/w two veritces.
// NO self loops in the graph

// Approach: Use DFS and parent array.

// Time Complexity:O(V+E)  Space Complexity:O(V+E)

bool dfs(vector<vector<int>> &graph, vector<bool> &visited, int src, int parent)
{
    visited[src] = 1;
    for (auto &nbd : graph[src])
    {
        if (!visited[nbd])
        {
            if (dfs(graph, visited, nbd, src)) // imp line
                return 1;
        }
        else if (parent != nbd)
        {
            return 1;
        }
    }

    return 0;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    vector<vector<int>> graph(n);
    vector<bool> visited(n, 0);

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
            if (dfs(graph, visited, i, -1))
            {
                return "Yes";
            }
        }
    }

    return "No";
}

int main()
{

    return 0;
}