#include <iostream>
#include <vector>

using namespace std;

// If cycle is present return 1 else 0
// Cycle must contain atleast 2 nodes
// No self loops in the graph.
// Graph may or may not be connected
// Nodes numbered from 1 to N.

bool dfs(vector<vector<int>> &graph, vector<bool> &visited, int src, vector<bool> &recStack)
{
    visited[src] = 1;
    recStack[src] = 1;
    for (auto &nbd : graph[src])
    {
        if (!visited[nbd])
        {
            if (dfs(graph, visited, nbd, recStack))
                return 1;
        }
        else if (recStack[nbd])
        {
            return 1;
        }
    }

    recStack[src] = 0;

    return 0;
}

// Approach: There is a cycle in a graph only if there is a back edge present in the graph.
// To check that we use RecStack that keep track of visited vertices in a particular path
// when (visited[i] && recStack[i]) are both high, we have a cycle

// Time Complexity: O(V+E) Space Complexity:O(V+E)
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    vector<vector<int>> graph(n);
    vector<bool> visited(n, 0);

    vector<bool> recStack(n, 0); // to keep track of visited verices in a particular path from src

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1; // 1-indexing
        int v = edges[i].second - 1;

        graph[u].push_back(v);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(graph, visited, i, recStack))
                return 1;
        }
    }

    return 0;
}

int main()
{

    return 0;
}
