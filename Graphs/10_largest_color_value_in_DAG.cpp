//  Leetcode 1857
// Crazy good question


#include<bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int>> &adjl, string &colors, vector<vector<int>> &col, vector<int> &indegree){
    int ans = 0;
    queue<int> q;
    for(int i = 0; i <indegree.size();i++)
        if(indegree[i]==0) q.push(i);
    
    while(!q.empty()){
        int n = q.front();
        q.pop();
        ans = max(++col[n][colors[n]-'a'], ans);
        

        for(auto i:adjl[n]){
            indegree[i]--;
            for(int j = 0; j < 26; j++)
                col[i][j] = max(col[i][j], col[n][j]);
            
            if(indegree[i]==0)
                q.push(i);
        }
    }

    for(auto i:indegree)
        if(i>0) return -1;
    return ans;

}
int largestPathValue(string colors, vector<vector<int>>& edges) {
    vector<vector<int>> adjl(colors.size());
    vector<int> indegree(colors.size(), 0);
    vector<vector<int>> col(colors.size(), vector<int>(26, 0));
    for(auto i:edges){
        adjl[i[0]].push_back(i[1]);
        indegree[i[1]]++;        
    }

    return bfs(adjl, colors, col, indegree);
}

int main(){

}