#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>

using namespace std;


template<typename T>
class graph{
    public:
    unordered_map<T,list<T>> adj;

    vector<vector<T>> adjList;

    void addEdge(T u, T v, bool dir){
        // dir=0 for directed graph
        // dir=1 for undirected graph

        adj[u].push_back(v);

        if(dir){
          adj[v].push_back(u);  
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<"-->";
            for(auto j:i.second){
                cout<<j<<"  ";
            }
            cout<<endl;
        }
    }
};

void bfs(unordered_map<int, list<int>>& adjList,unordered_map<int,bool>& visited,vector<int>& ans, int node){

    queue<int> q;
    visited[node]=1;
    q.push(node);
    

    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        ans.push_back(frontNode);

        for(auto nbd:adjList[frontNode]){
            if(!visited[nbd]){
                visited[nbd]=1;
                q.push(nbd);
            }
            
        }
    }

}


// vertex: no of vertex
vector<int> BFS(int vertex, vector<pair<int,int>> edges){

    unordered_map<int, list<int>> adjList;// set store the answer in sorted order
    vector<int> ans;
    unordered_map<int,bool>visited; // vector<int> visited(vertex,0);

    //prepare adjancecy list

    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // traverse all components of a graph

    for(int i=0;i<vertex;i++){
        if(!visited[i])
        bfs(adjList,visited,ans,i);
    }

    return ans;
    
}

void dfs( unordered_map<int,list<int>>& adj,unordered_map<int,bool>& visited,vector<int>& component,int node){
    visited[node]=1;
    component.push_back(node);
    for(auto nbd:adj[node]){
        if(!visited[nbd])
        dfs(adj,visited,component,nbd);
    }
}

vector<vector<int>> DFS(int V,vector<vector<int>>& edges){
    //prepare adjacency list
    vector<vector<int>> ans;
    unordered_map<int,list<int>> adj;
    unordered_map<int,bool> visited;

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(adj,visited,component,i);
            ans.push_back(component);
        } 
    }

}

int main(){
    int n;
    cout<<"Enter no of vertices:";
    cin>>n;

    int m;
    cout<<"Enter no of edges:";
    cin>>m;

    graph<int> g;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,1);
    }

    g.printAdjList();


    return 0;
}