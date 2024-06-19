#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// A bridge in any graph is defined as an edge which, when removed, makes the graph disconnected.(or more precisely, increases the number of connected components in the graph)

// Need to find all bridges in the given undirected graph
// No self loops and parallel edges are present in the graph
// Ouput: In each line contains one edge like(0 4).

// Approach 1: 1)Brute Force: For each edge, check wheher no of componnets increase or Not using DFS
// Time COmplexity:O(E*(V+E))

// TARZAN ALGO
// Approach 2: Need 4 auxillary data structures:
// disc[N]: to keep track when for the first time that paticular vertex is reached.

// low[N]: to keep track of the lowest possible time by which we can reach that vertex ‘other than parent’ so that if edge from parent is removed can the particular node can be reached other than parent.

// visited[N]: to keep track of visited vertices to implement DFS.
// parent[N]: to keep track of parent of each node OR (can pass as a parameter in DFS )

// {whenver we have a case of back edge, we need to upgrade low}: low[node]=min(low[node], disc[nbd]) bcoz it might be accesible from that node; if(nbd==parent) ignore

// while returning from DFS, if any low vector of child is updated, we need to check and update low of that vertex:  low[node]=min(low[node], disc[child]); if(nbd==parent) ignore

// To check bridge while backtracking: low[nbd] > disc[node] ==> BRIDGE {It means this is the only path to reach nbd from that node}, otherwise if we have a back edge, then low [nbd] gets lower value & this condition is NOT satisfied.

void dfs(unordered_map<int, list<int>> &adj, vector<bool> &visited, vector<int> &disc, vector<int> &low, int &timer, int parent, int src, vector<vector<int>> &ans)
{
    visited[src] = 1;
    disc[src] = timer++;
    low[src] = timer++;

    for (auto &nbd : adj[src])
    {
        if (nbd == parent)
            continue;
        else if (visited[nbd])
        {
            // back edge is posiible
            low[src] = min(low[src], disc[nbd]);
        }
        else if (parent != nbd)
        {
            dfs(adj, visited, disc, low, timer, src, nbd, ans);

            // need to update low of src if any low of child is updated
            low[src] = min(low[src], low[nbd]); // child ,may be connected via back edge

            // check for bridge
            if (low[nbd] > disc[src])
            {
                vector<int> temp;
                temp.push_back(src);
                temp.push_back(nbd);
                ans.push_back(temp);
            }
        }
    }
}

// Time Complexity:O(V+E) Space Complexity:O(V)
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    vector<vector<int>> ans;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(v, 0);
    vector<int> disc(v, -1);
    vector<int> low(v, -1);

    int timer = 0;
    int parent = -1;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(adj, visited, disc, low, timer, parent, i, ans);
        }
    }

    return ans;
}

int main()
{

    return 0;
}