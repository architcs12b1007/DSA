#include <iostream>
#include <vector>

using namespace std;

// V: No of vertices numbered from 0 to V-1.
// Graph may not be connected (exist multiple components in a graph)

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int src, vector<int> &singleComponent)
{
    visited[src] = 1;
    singleComponent.push_back(src);

    for (auto &nbd : graph[src])
    {
        if (!visited[nbd])
        {
            dfs(graph, visited, nbd, singleComponent);
        }
    }
}

// Time Complexity:O(V+E) Space Complexity:O(V+E)
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    vector<vector<int>> graph(V); // unordered_map<int, vector<int>> (if nodes are represented by character)

    vector<bool> visited(V, false);

    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> singleComponent;
            dfs(graph, visited, i, singleComponent);
            ans.push_back(singleComponent);
        }
    }

    return ans;
}

int main()
{

    return 0;
}
