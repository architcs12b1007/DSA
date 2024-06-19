#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

bool isCyclicBFS(int node,unordered_map<int,bool>& visited,unordered_map<int,list<int>>& adj){
    queue<int> q;
    unordered_map<int,int> parent;
    parent[node]=-1;
    visited[node]=1;
    q.push(node);
    
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();

        for(auto nbd:adj[frontNode]){
            
            if(visited[nbd]==1 && parent[frontNode]!=nbd)
            return 1;
           
            if(!visited[nbd]){
                parent[nbd]=frontNode;
                visited[nbd]=1;
                q.push(nbd);
            }

            
        }

    }

    return 0;
}

bool isCyclicDFS(int node,unordered_map<int,bool>& visited,unordered_map<int,list<int>>& adj,int parent){
    visited[node]=1;
    for(auto nbd:adj[node]){
        // if(visited[nbd]==1 && parent!=nbd)
        // return true;

        if(!visited[nbd]){
            bool cycleDetected=isCyclicDFS(nbd,visited,adj,node);
            if(cycleDetected==1)
            return true;
        }
        else if(parent!=nbd)
        return true;
    }

    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m){
    // create adjacency list

    unordered_map<int,list<int>> adj;
    unordered_map<int,bool> visited;


    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    //to handle disconnected components

    for(int i=0;i<n;i++){
        if(!visited[i]){
            // bool ans=isCyclicBFS(i,visited,adj);
            bool ans=isCyclicDFS(i,visited,adj,-1);
            if(ans==1)
            return "Yes";

        }

    }

    return "No";
}

bool checkCycleDFS(int node,unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsvisited){

    visited[node]=1;
    dfsvisited[node]=1;

    for(auto nbd:adj[node]){
        if(!visited[nbd]){
            bool ans=checkCycleDFS(nbd,adj,visited,dfsvisited);
            if(ans==1)
            return true;
        }
        else if(dfsvisited[nbd])
        return true;
    }
    dfsvisited[node]=0;
    return false;

}

int detectCycleInDirectedGraph(int n,vector<pair<int,int>>& edges){

    // create adjacency list

    unordered_map<int,list<int>> adj;
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsvisited;


    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);

    }

    //call dfs for all components

    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool cycleFound=checkCycleDFS(i,adj,visited,dfsvisited);
            if(cycleFound==1)
            return 1;
        }
    }

    return 0;
}

int main(){
    return 0;
}