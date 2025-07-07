#include<bits/stdc++.h>

using namespace std;


class Solution {
  public:
    bool dfs(int node, vector<int> adjl[], vector<int> &visited, vector<int> &cp){
            visited[node] = 1;
            cp[node] = 1;
            
            for(auto i:adjl[node]){
                if(cp[i])
                    return true;
                if(!visited[i])
                    if(dfs(i, adjl, visited, cp)) return true;
            }
            
            cp[node]=0;
            visited[node]=0;
            return false;
        }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
            // code here
            vector<int> visited(V, 0), cp(V,0), ans;
            
            for(int i = 0; i < V; i++){
                if(!dfs(i, adj, visited, cp))
                    ans.push_back(i);
            }
            
            return ans;
        }
};



// ------------------------------------------alternate solution-----------------------------------------


    bool dfs(int node, vector<int> adjl[], vector<int> &visited, vector<int> &cp){
            visited[node] = 1;
            cp[node] = 1;
            
            for(auto i:adjl[node]){
                if(cp[i])
                    return true;
                if(!visited[i])
                    if(dfs(i, adjl, visited, cp)) return true;
            }
            
            cp[node]=0;
            // visited[node]=0;
            return false;
        }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
            // code here
            vector<int> visited(V, 0), cp(V,0), ans;
            
            for(int i = 0; i < V; i++){
                if(!visited[i])
                    dfs(i, adj, visited, cp);
            }
            
            for(int i = 0; i < V; i++){
                if(!cp[i])
                    ans.push_back(i);
            }
            
            return ans;
        }


int main (){

}