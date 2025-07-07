// GFG question: 5927
#include<bits/stdc++.h>

using namespace std;


const int dirs[8][2] = {{-2,-1}, {-1,-2}, {-1,2}, {-2,1}, {1,-2}, {2,-1}, {2,1}, {1,2}};
int bfs(vector<vector<int>> &visited, vector<int> &pos, vector<int> t, int N){
        queue<vector<int>> q;
        q.push({pos[0], pos[1]});
        int depth = 0;
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front()[0];
                int y = q.front()[1];
                if(x == t[0] and y == t[1])
                            return depth;
                for(auto dir:dirs){
                    int nx = x+dir[0];
                    int ny = y+dir[1];
                    if(nx >0 and ny>0 and nx< N+1 and ny<N+1){
                        if(!visited[nx][ny])
                        {visited[nx][ny] = 1;
                        q.push({nx,ny});}
                   }
                }
                q.pop();
            }
            depth++;
        }
        
        return -2;
    }

    
int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int N) {
        vector<vector<int>> visited(N+1, vector<int>(N+1,0));
        return bfs(visited, knightPos, targetPos, N);
    }