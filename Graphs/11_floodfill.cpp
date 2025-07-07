#include<bits/stdc++.h>

using namespace std;


const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0,1}, {0,-1}};
void dfs_floodfill(vector<vector<int>> &image, int r, int c, int color, int oc){
    if(r<0 or c<0 or r>=image.size() or c>=image[0].size())
        return;
    if(image[r][c]!=oc)
        return;
    image[r][c] = color;
    for(auto i:dirs)
        dfs_floodfill(image, r+i[0], c+i[1], color, oc);
}

void bfs_floodfill(vector<vector<int>> &image, int r, int c, int color, int oc){
    queue<pair<int,int>> q;
    q.emplace(r, c);

    while(!q.empty()){
        pair<int, int> val = q.front();
        q.pop();
        image[val.first][val.second] = color;

        for(auto i:dirs){
            int x = i[0]+val.first;
            int y = i[1]+val.second;

            if(x >= 0 and y >=0 and x < image.size() and y < image[0].size())
                if(image[x][y] == oc) q.emplace(x,y);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if(image[sr][sc]!=color)
        bfs_floodfill(image, sr, sc, color, image[sr][sc]);
        // dfs_floodfill(image, sr, sc, color, image[sr][sc]);
    return image;
}


int main(){

}