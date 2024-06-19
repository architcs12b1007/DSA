#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

vector<int> TopologicalSortDFS(vector<vector<int>>& edges, int v, int e){
    // create adjacency list

    unordered_map<int,list<int>> adj;
    vector<int> ans;
    
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }

    // find all indegrees
    vector<int> indegree(v);

    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    //push 0 indegree nodes

    queue<int> q;
    int count=0;

    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    

    //do bfs

    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        count++;

        ans.push_back(frontNode);
        for(auto nbd:adj[frontNode]){
            indegree[nbd]--;

            if(indegree[nbd]==0){
                q.push(nbd);
                
            }
        }
    }
    // if(count==v)
    // cout<<"Cycle NOT Present";
    // else
    // cout<<"Cycle Presenr"<<endl;

    return ans;
}

int main(){
    
    return 0;
}