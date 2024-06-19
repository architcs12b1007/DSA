#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// If cycle is present return 1 else 0
// Cycle must contain atleast 2 nodes
// No self loops in the graph.
// Graph may or may not be connected
// Nodes numbered from 1 to N.

// Approach: Topological Sorting using Kahn Algo (only poosible for DAG)

// Need to find indegree of all vertices. Push all vertices in the queue whose indegree to 0.
// Initialize count is 0. Make while loop until q is empty.
// Remove vertices whose indegree is 0 ans so we need to decrese all nbd indegree by 1.
// Insert nbd vertices in queue if its indegree is 0 betweent the process.
// Increment the count when we pop element from queue.
// If count is N. // No cycle present ==> Topological sorting possible (DAG)

// Time Complexity:O(V+E)  Space Complexity:O(V+E)

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    vector<vector<int>> graph(n);
    vector<bool> visited(n, 0);
    vector<int> indegree(n, 0);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        graph[u].push_back(v);

        indegree[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0; // to keep track of number of vertices

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        count++;
        // node is in your topo sort
        // so please remove it from the indegree
        for (auto &nbd : graph[curr])
        {
            indegree[nbd]--;
            if (indegree[nbd] == 0)
            {
                q.push(nbd);
            }
        }
    }

    if (count == n)
        return 0; // cycle NOT Present
    else
        return 1;
}

int main()
{

    return 0;
}
