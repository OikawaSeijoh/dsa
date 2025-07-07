// Geeks for geeks question: search for Dijkstra's practice
#include<bits/stdc++.h>

using namespace std;

// Dijkstras in normal graphs
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int> distance(V, INT_MAX);
        distance[src] = 0;
        vector<vector<pair<int, int>>> adjl(V);
        for(auto i:edges){
            adjl[i[0]].push_back({i[1], i[2]});
            adjl[i[1]].push_back({i[0], i[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        
        while(!pq.empty()){
            pair<int, int> node = pq.top();
            int dist = node.first;
            int n = node.second;
            pq.pop();
            
            for(auto i: adjl[n]){
                int cur_dist = dist+i.second;
                int nbr = i.first;
                
                if(distance[nbr]>cur_dist){
                    pq.push({cur_dist, nbr});
                    distance[nbr] = cur_dist;
                }
            }
        }
        
        return distance;        
}

//Dijkstras in grid

const vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int minimumEffortPath(vector<vector<int>>& heights) {
            vector<vector<int>> distance(heights.size(), vector<int>(heights[0].size(), INT_MAX));
            priority_queue<pair<int, pair<int, int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int, int>>>> pq;
            pq.push({0, {0, 0}});
            distance[0][0] = 0;

            while(!pq.empty()){
                pair<int, pair<int, int>> qobject = pq.top();
                int dist = qobject.first;
                int x = qobject.second.first;
                int y = qobject.second.second;
                pq.pop();
                for(auto i:dirs){
                    int a = i[0]+x;
                    int b = i[1] + y;
                    if(a>=0 and b >=0 and a <heights.size() and b < heights[0].size()){
                        int curdist = dist +abs(heights[x][y] - heights[a][b]);
                        if(curdist < distance[a][b]){
                            pq.push({curdist, {a, b}});
                            distance[a][b] = curdist;
                        }
                    }
                }

            }
            return distance[heights.size()-1][heights[0].size()-1];
        }

int main(){

}
