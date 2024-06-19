#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

int countTriplets(vector<int>& a, int d){
    int count=0;

    unordered_map<int,int> hash_map;

    for(int i=0;i<a.size();i++){
        if(hash_map.count(a[i]-d) && hash_map.count(a[i]-2*d)){
            count+=(hash_map[a[i]-d]*hash_map[a[i]-2*d]);
        }

        if(!hash_map.count(a[i])){
            hash_map[a[i]]=1;
        }
        else{
             hash_map[a[i]]+=1;
        }
    }

    return count;
}

int main(){

    vector<int> v{1,6,7,7,8,10,12,13,14};
    int d=3;

    //vector<int> v{3,2,5,8,10,11};
    //int d=3;
    cout<<countTriplets(v,d);

    return 0;
}


void iterative(vector<vector<int>> graph, vector<bool>& visited, int node, void(*fn)(int)){
    stack<int> s;
    s.push(node);
    while(!s.empty()){
        int temp=s.top();
        s.pop();
        if(!visited[temp]){
            fn(node);
            visited[temp]=true;
        }

        for(auto i=graph[temp].begin();i!=graph[temp].end();i++){
            if(!visited[*i])
            s.push(*i);
        }
    }
}