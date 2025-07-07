//LC 1319

#include<bits/stdc++.h>

using namespace std;


// My Solution: Calculate number of cyclic connecions, number of components, answer will be no of components -1, if number of components is less than number of cyclic connections. else -1, have to deal with the case of 1 component 0 extra connections
int bfs(vector<vector<int>>& adjl, vector<int>& visited, int node, vector<int>& parent){
        int count = 0;
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while(!q.empty()){
            int n = q.front();
            q.pop();

            for(auto i:adjl[n]){
                if(!visited[i]){
                    visited[i] = 1;
                    parent[i] = n;
                    q.push(i);
                }

                else if(parent[n]!=i)
                    count++;
            }
        }

        return count;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjl(n);
        vector<int> visited(n, 0), parent(n, -1);
        
        for(auto i:connections){
            adjl[i[0]].push_back(i[1]);
            adjl[i[1]].push_back(i[0]);
        }
        int comps = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count+= bfs(adjl, visited, i, parent);
                comps++;
                }
        }
        cout << "comps: " << comps << " count: " << count << endl;
        // if(comps == 1) return 0;
        return count>=comps or comps==1?comps-1:-1;
    }

// This is AV's solution and slightly better in terms of not having to use parent array. He using the fact that to connect n nodes, n-1 connections are needed. This doesnt translate to if there are less than n-1 nodes then there cannot be a cycle.
void bfs(vector<vector<int>>& adjl, vector<int>& visited, int node){
int count = 0;
queue<int> q;
q.push(node);
visited[node] = 1;

while(!q.empty()){
    int n = q.front();
    q.pop();

    for(auto i:adjl[n]){
	if(!visited[i]){
	    visited[i] = 1;
	    q.push(i);
	}
    }
}

}
int makeConnected(int n, vector<vector<int>>& connections) {
vector<vector<int>> adjl(n);
vector<int> visited(n, 0), parent(n, -1);
// if(connections.size()<n-1)
//     return -1;

for(auto i:connections){
    adjl[i[0]].push_back(i[1]);
    adjl[i[1]].push_back(i[0]);
}
int comps = 0;

for(int i = 0; i < n; i++){
    if(!visited[i]){
	bfs(adjl, visited, i);
	comps++;
	}
}

int count = (n-1) - connections.size();
return count>0?-1:comps-1;
return comps-1;
// if(comps == 1) return 0;
// return count>=comps or comps==1?comps-1:-1;
}
