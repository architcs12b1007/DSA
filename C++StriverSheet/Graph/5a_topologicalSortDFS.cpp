#include <iostream>
#include <vector>

using namespace std;

// Given a DAG( Directed Acyclic Graph ), print all the vertex of the graph in a topologically sorted order. If there are multiple solutions, print any.

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int src, vector<int> &ans)
{
    visited[src] = 1;

    for (auto &nbd : graph[src])
    {
        if (!visited[nbd])
            dfs(graph, visited, nbd, ans);
    }

    ans.push_back(src);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    vector<int> ans; // can take stack as well
    vector<vector<int>> graph(v);
    vector<bool> visited(v, 0);

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        graph[u].push_back(v);
    }

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            dfs(graph, visited, i, ans);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
int main()
{

    return 0;
}
