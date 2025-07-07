// Leetcode: 2630
//  Had the correct idea with populating cp with current_depth and the calculation of depth+1-cp[edges[node]]
//  What I did not get correct was that at each return, we need to depopulate the cp array so that any other potential paths can be populated.
// With a void function since there is no return value, the last statement for cp[node] = 0 runs in all cases whether or not we have found the longest cycle.

#include<bits/stdc++.h>

using namespace std;
int dfs(int node, vector<int> &edges, vector<int> &visited, vector<int> &cp, int depth){
        depth++;
        cp[node] =  depth;
        visited[node] = 1;
        
        if(edges[node]==-1){
            cp[node]= 0;
            return -1;}
        if(cp[edges[node]]!=0){
            
            int val =  depth+1-cp[edges[node]];
            cp[node] =  0;
            return val;
        }
        if(!visited[edges[node]]){
            int ans = dfs(edges[node], edges, visited, cp, depth);
            cp[node]=0;
            if(ans!=-1) return ans;
            }
        cp[node]=0;
        return -1;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n,0), cp(n, 0);
        int answer = -1;
        for(int i = 0; i < edges.size(); i++){
            if(!visited[i]) answer = max(answer, dfs(i, edges, visited, cp, 0));
        }
        return answer;
    }



// -----------                 AV Solution         ---------------------------------------

int answer = -1;
void dfs_v(int node, vector<int> &edges, vector<int> &visited, vector<int> &cp, int depth){
    depth++;
    cp[node] =  depth;
    visited[node] = 1;
    
    if(edges[node]==-1){
        cp[node]=0;
        return;
    }
    if(cp[edges[node]]!=0)
        answer = max(answer, depth+1-cp[edges[node]]);
    
    if(!visited[edges[node]])
        dfs(edges[node], edges, visited, cp, depth);
    cp[node]=0;
}

int longestCycle(vector<int>& edges) {
    int n = edges.size();
    vector<int> visited(n,0), cp(n, 0);
    
    for(int i = 0; i < edges.size(); i++){
        if(!visited[i]) dfs_v(i, edges, visited, cp, 0);
    }
    return answer;
}


int main(){

}