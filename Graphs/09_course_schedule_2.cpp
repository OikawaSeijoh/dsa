//  leetcode 210
//  Dfs is a bit tricky cause handling cycles is needed

#include<bits/stdc++.h>


using namespace std;

class Solution {
public:

    deque<int> dq;
    bool dfs(vector<vector<int>> &adjl, vector<int> &visited, int node){
        visited[node] = 1;
        for(auto i: adjl[node]){
            if(visited[i]==1)
                return false;
            if(!visited[i])
                if(!dfs(adjl, visited, i)) return false;
        }

        dq.push_front(node);
        visited[node]=2;
        return true;
    }
    vector<int> bfs(vector<vector<int>> &adjl, vector<int> &indegree){
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i < indegree.size(); i++)
            if(indegree[i]==0) q.push(i);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
                for(auto i: adjl[node]){
                    indegree[i]--;
                    if(!indegree[i])
                        q.push(i);
                }
        }

        if(ans.size()==indegree.size())
            return ans;
        return {};
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;

        vector<vector<int>> adjl(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto i: prerequisites){
            adjl[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }

        vector<int> visited(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]) 
                if(!dfs(adjl, visited, i)) return {};}
        for(auto i:dq)
            ans.push_back(i);
        return ans.size()==numCourses? ans:vector<int> {};
        // return bfs(adjl, indegree);
        
    }
};