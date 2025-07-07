#include<bits/stdc++.h>

using namespace std;




int bfs(vector<int> &graph, vector<int> &answer, vector<int>& visited){
        queue<int> q;
        q.push(0);
        int depth = 0;
        visited[0]=1;
        answer[0] = depth;
        while(!q.empty()){
            int size = q.size();
            depth++;
            while(size--){
                int node = q.front();
                q.pop();
                for(int i = 1; i <= 6; i++){
                    int next = node+i;
                    if(next>=answer.size()) break;
                    int dest = graph[next]==-1? next: graph[next]-1;
                    if(!visited[dest]){
                        visited[dest] = 1;
                        q.push(dest);
                        answer[dest] = depth;
                    }

                }
            }
        }
            
            
        
        int val = answer[answer.size()-1];
        return val!=INT_MAX? val:-1;
    }

