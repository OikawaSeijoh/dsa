// Leeetcode 1631

#include<bits/stdc++.h>

using namesapce std;
const vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}
int minimumEffortPath(vector<vector<int>>& heights) {
	vector<vector<int>> distance(heights.size(), vector<int>(heights[0].size(), INT_MAX));
	priority_queue<pair<int, pair<int, int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int, int>>>> pq;
	pq.push({0, {0, 0}};
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
			if(x>=0 and y >=0 and x <heights.size() and y < heights[0].size()){
				int curdist = dist +abs(heights[x][y] - heights[a][b]);
				if(curdist < distance[a][b]){
					pq.push({curdist, {a, b}});
					distance[a][b] = curdist;
				}
			}
		}
		
	}	
	return distance[heights.size()][heights[0].size()];
}    
