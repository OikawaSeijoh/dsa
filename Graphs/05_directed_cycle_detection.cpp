// GFG question
#include<bits/stdc++.h>

using namespace std;



bool dfs(int node, vector<int> &visited, vector<int> &cp, const vector<vector<int>> &adjl){
    visited[node] = 1;
    cp[node] = 1;
    
    for(auto i:adjl[node]){
        if(cp[i])
            return true;
        if(!visited[i])
            if(dfs(i, visited, cp, adjl)) return true;
    }
    
    cp[node] = 0;
    return false;
}
bool isCyclic(int V, vector<vector<int>> &edges) {
    // code here
    vector<vector<int>> adjl(V);
    vector<int> visited(V, 0);
    vector<int> cp(V,0);

    for(auto i: edges)
        adjl[i[0]].push_back(i[1]);
    
    for(int i = 0; i < V; i++){
    if(!visited[i])
        if (dfs(i, visited, cp, adjl)) return true;
    
    }
    return false;
}


int main(){

}