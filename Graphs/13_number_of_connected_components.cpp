// Number of connected components LC 1319

#include<bits/stdc++.h>


using namespace std;

vector<vector<int>> answer;
void bfs(int node, vector<vector<int>> &adjl, vector<int> &visited){
vector<int> ans;
visited[node] = 1;

queue<int> q;
q.push(node);
while(!q.empty()){
    int n= q.front();
    q.pop();
    ans.push_back(n);
    
    for(auto i:adjl[n]){
	if(!visited[i]){
	    visited[i] = 1;
	    q.push(i);
	}
    }
}
answer.push_back(ans);
}
vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
vector<vector<int>> adjacency_list(V);
vector<int> visited(V, 0);
for(auto i:edges){
    adjacency_list[i[0]].push_back(i[1]);
    adjacency_list[i[1]].push_back(i[0]);
}

for(int i = 0; i < V; i++)
    if(!visited[i]) bfs(i, adjacency_list ,visited);
    
return answer;    


}


int main(){
}
