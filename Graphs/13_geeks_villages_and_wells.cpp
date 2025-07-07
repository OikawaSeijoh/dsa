#include<bits/stdc++.h>

using namespace std;

const vector<vector<int>> dirs = {{1,0}, {0,1}, {-1, 0}, {0, -1}};    
vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &c) {
    // Code here
    vector<vector<int>> ans(n, vector<int>(m, -1));    
    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(c[i][j] == 'W'){
                q.push({i, j});
                ans[i][j] = 0;  // Very important
            } 
            
        }
    }
    int depth = 0;
    while(!q.empty()){
        int size = q.size();
        // cout << " size =" << size << endl;
        // cout << depth++ << endl;
        depth++;
        while(size--){
            pair<int, int> node = q.front();
            q.pop();
            
            for(auto i: dirs){
                int x = node.first + i[0];
                int y = node.second + i[1];           
                if(x >= n or y >= m or x < 0 or y < 0 ) continue;
                if((c[x][y]=='N' or c[x][y] == 'W') and ans[x][y]==-1) ans[x][y] = 0;
                else if( ans[x][y] == -1){
                    q.push({x,y});
                    ans[x][y] = c[x][y]=='H'? depth*2: 0;
                    }
            }
        }
        
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(c[i][j] != 'H') ans[i][j] = 0;
            
        }
    }

    return ans;
}

int main(){

}