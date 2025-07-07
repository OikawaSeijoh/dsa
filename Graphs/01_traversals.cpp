#include<bits/stdc++.h>

using namespace std;

void print_bfs(unordered_map<int, vector<int>> &adjl, int node, vector<int> &visited){
    
    queue<int> qu;
    qu.push(node);
    int depth = 0;
    visited[node] = 1;
   
    while(!qu.empty()){
        int size = qu.size();
        while(size--){
            cout << qu.front()<< " level: " << depth <<endl;
            visited[qu.front()] = 1;
            for(auto i:adjl[qu.front()]){
                if(!visited[i]) qu.push(i);
            }
            
            qu.pop();
        }
        depth++;
    }
    cout << endl;
}

void print_dfs(unordered_map<int,vector<int>> adjl, int node, vector<int> &visited){
    cout << node << " ";
    visited[node] = 1;
    
    for(auto i: adjl[node])
        if(visited[i] == 0) print_dfs(adjl, i, visited);

}

int main()
{
    vector<vector<int>> edge_list = {{1,2}, {1,3}, {1,4}, {1,5}, {2,6}, {3,7}, {4,8}, {5,9}, {6,10}};
    
    unordered_map<int, vector<int>> adjl;
    for(auto i:edge_list){
        adjl[i[0]].push_back(i[1]);
        adjl[i[1]].push_back(i[0]);
    }
    
    vector<int> visited(11, 0);
    
    cout << "printing BFS traversal: " << endl;
    print_bfs(adjl, 1, visited);
    
    vector<int> visited_2(11, 0);
    cout << "printing DFS traversal: ";
    print_dfs(adjl, 1, visited_2);
    
    
    
    
    return 0;
}