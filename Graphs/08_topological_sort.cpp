#include<bits/stdc++.h>

using namespace std;

deque<int> dq;
void bfs(vector<int> &indegree, vector<vector<int>> &adjl){
    queue<int> q;
    
    for(int i = 0; i < indegree.size(); i++){
        if(indegree[i]==0) 
        q.push(i);
        
    }
    
    while(!q.empty()){
        int n = q.front();
        cout << n << " ";
        q.pop();

        
        for(auto i:adjl[n]){
            indegree[i]--;
            if(indegree[i]==0)
                q.push(i);
        }

    }
    
    
}

//  ---------------------- another solution---------------------
vector<int> answer;
void dfs(vector<vector<int>> &adjl, vector<int> &indegree, vector<int> &visited, int node){
    answer.push_back(node);
    visited[node] = 1;
    
    for(auto i: adjl[node]){
        if(!--indegree[i] and !visited[i]){
            dfs(adjl, indegree, visited, i);
        }
    }
}
//  ---- this cock sucker doesnt detect cycles------
deque<int> dq;
    void dfs(int node, vector<int> &visited, vector<vector<int>> &adjl){
        visited[node] = 1;
        for(auto i: adjl[node]){
            if(!visited[i])
                dfs(i, visited, adjl);
        }
        
        dq.push_front(node);
    }

int main()
{
    int n=6;
    vector<vector<int>> adjl = {{2},{2},{4,3},{5},{5},{}};

//  ------------bfs-------------
    vector<int> indegree(n, 0);
    for(auto i:adjl){
        for(auto j: i)
            indegree[j]++;
    }
    bfs(indegree, adjl);

//  ------------dfs------------
    vector<int> visited(n, 0);
    for(int i = 0; i < n; i++)
        if(!visited[i]) dfs(i, visited, adjl);
    vector<int> answer;
    for(int i:dq)
        answer.push_back(i);

    return 0;


}