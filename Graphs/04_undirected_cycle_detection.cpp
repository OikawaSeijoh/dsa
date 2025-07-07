#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int> &visited, vector<vector<int>> &adjl){
    visited[node] = 1;
    for(auto i: adjl[node]){
        if(!visited[i])
            {if(dfs(i, node, visited, adjl)) return true;}
        else
            if(i!=parent) return true;
    }
    return false;
}

bool bfs(int node, vector<int> &parent, vector<vector<int>> &adjl, vector<int> &visited){
    visited[node]=1;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int n = q.front();
        for(auto i:adjl[n]){
            if(!visited[i]){
                q.push(i);
                parent[i] = n;
                visited[i]=1;
            }
            else
                if(parent[n]!=i) return true;
        }
        q.pop();
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
    // Code here
    vector<vector<int>> adjl(V);
    vector<int> visited(V, 0);
    for(auto i: edges){
        adjl[i[0]].push_back(i[1]);
        adjl[i[1]].push_back(i[0]);
    }
    
    for(int i = 0; i < V; i++){
        if(!visited[i])
            if(dfs(i, -1, visited, adjl)) return true;
    }
    
    return false;
}
