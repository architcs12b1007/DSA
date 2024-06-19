#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Topological Sorting: The linear ordering of nodes/vertices such that if there exists an edge between 2 nodes u,v then ‘u’ appears before ‘v’.

// Given a DAG( Directed Acyclic Graph ), print all the vertex of the graph in a topologically sorted order. If there are multiple solutions, print any.

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    vector<int> ans;
    vector<vector<int>> graph(v);
    vector<int> indegree(v, 0);

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        graph[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);

        for (auto &nbd : graph[curr])
        {
            indegree[nbd]--;
            if (indegree[nbd] == 0)
                q.push(nbd);
        }
    }

    return ans;
}

int main()
{

    return 0;
}
