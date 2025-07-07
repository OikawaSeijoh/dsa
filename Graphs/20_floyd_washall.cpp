#include<bits/stdc++.h> 

using namespace std;

// This doesnt detect negative weight cycle, to do this, run the loop again and if any relaxation is happening, it means its a negative weight cycle.
void floydWarshall(vector<vector<int>> &dist) {
      for(int k = 0; k < dist.size(); k++){
	      for(int i = 0; i < dist.size(); i++){
		      if(i==k or dist[i][k]==100000000) continue;
		      for(int j = 0; j < dist.size(); j++){
			      if(j==k or j == i or dist[k][j]==100000000) continue;
			      dist[i][j] =  min(dist[i][j], dist[i][k] + dist[k][j]);
		      }
	      }
      } 

}


int main(){
}
