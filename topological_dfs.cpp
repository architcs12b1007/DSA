#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

void topoSort(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj,stack<int> &s){
    visited[node]=1;
    for(auto nbd:adj[node]){
        if(!visited[nbd]){
            topoSort(nbd,visited,adj,s);
        }
    }

    // important
    s.push(node);
}

vector<int> TopologicalSortDFS(vector<vector<int>>& edges, int v, int e){
    // create adjacency list

    unordered_map<int,list<int>> adj;
    
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }

    // call dfs topological sort for all components
    unordered_map<int,bool> visited; // vector<int> visited(n);
    stack<int> s;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            topoSort(i,visited,adj,s);
        }
    }

    vector<int> ans;

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main(){
    
    return 0;
}