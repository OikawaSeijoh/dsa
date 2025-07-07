// Leet code 1466

#include<bits/stdc++.h>

using namespace std;


// # First approach ------------------------------------------------------------------ Time limit exceeded -------------------------------------
int dfs(unordered_map<int, vector<int>> dir, unordered_map<int, vector<int>> bidir, int node, vector<int> &visited){
    int count= 0;
    
    visited[node]=1;
    for(auto i: bidir[node]){
        if(!visited[i]){
            if(find(dir[node].begin(), dir[node].end(), i)!=dir[node].end())
                count++;
            count+=dfs(dir, bidir, i, visited);}
            
    
    }
    return count;
}
int minReorder(int n, vector<vector<int>>& connections) {
    unordered_map<int, vector<int>> dir;
    unordered_map<int, vector<int>> bidir;
    vector<int> visited(n, 0);
    for(auto i: connections){
        int x = i[0], y = i[1];
        dir[x].push_back(y);
        bidir[x].push_back(y);
        bidir[y].push_back(x);
        
    }

    return dfs(dir, bidir, 0, visited);
    
}
// -------------------------------------------------------------------------------------

//  I was thinking along the correct lines. instead of finding the node in dir, i should not add the node in bidir, that way  
//  the check for it to exist in dir is skipped, 


//  -----------------------------correct approach--------------------------------------

 int bfs(vector<vector<int>> &fadjl, vector<vector<int>> &badjl, int source, vector<int> &visited){
        queue<int> q;
        q.push(source);
        visited[source] = 1;
        int answer = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i: fadjl[node]){
                if(!visited[i]){
                    answer++;
                    visited[i] = 1;
                    q.push(i);
                }
            }
            for(auto i:badjl[node])
                if(!visited[i]){ 
                    q.push(i);
                    visited[i] = 1;
                }
        }

        return answer;
    }

  int dfs(vector<vector<int>> &forward, vector<vector<int>> &backward, int node, vector<int> &visited){
        int count= 0;
        visited[node]=1;
        for(int i: forward[node]){
            if(!visited[i]){
                count=count+1+dfs(forward, backward, i, visited);}
        }
        for(auto i: backward[node]){
            if(!visited[i])
                count+=dfs(forward,backward,i, visited);
            }
            return count;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> forward(n);
        vector<vector<int>> backward(n);
        vector<int> visited(n, 0);
        int ans = 0;
        for(auto i: connections){
            int x = i[0], y = i[1];
            forward[x].push_back(y);
            backward[y].push_back(x);
        }

        return dfs(forward, backward, 0, visited);
        
    }