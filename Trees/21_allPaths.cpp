#include<bits/stdc++.h>

using namespace std;

// Important thing is to ensure that not add path to paths if root is null cause then itll be added twice, for left and right nulls. only append if both are null.
void rfunc(Node*root, vector<vector<int>> &paths, vector<int> &path){
    if(!root) return;
    path.push_back(root->data);
    
    if(!root->left and !root->right)
        paths.push_back(path);
    rfunc(root->left, paths, path);
    rfunc(root->right, paths, path);
    path.pop_back();
    return;
}
vector<vector<int>> Paths(Node* root) {
    vector<vector<int>> paths;
    vector<int> path;
    rfunc(root, paths, path);
    return paths;
}

int main(){
}
