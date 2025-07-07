#include<bits/stdc++.h>

using namespace std;


vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
            
    	vector<int> distance(V, 100000000);
    	distance[src] = 0;
    	for(int count = 0; count<=V-1; count++){
    		for(auto i:edges){
    			if(distance[i[0]]!=100000000){
    				if(distance[i[0]]+i[2]<distance[i[1]]){
    				    if(count == V-1)
    				        return vector<int> {-1};
    					distance[i[1]] = distance[i[0]]+i[2];
    				}
    			}
    		}
    	}
    	if(distance[src]<0)
    	    return vector<int> {-1};
    	return distance;	
    }

int main(){
}
