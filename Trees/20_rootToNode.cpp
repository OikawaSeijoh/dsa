#include<bits/stdc++.h>


using namespace std;


bool dfs(TreeNode* root, int val, vector<int> &answer){
    if(!root) return false;
    answer.push_back(root->val);
    if(root->val == val) return true;
    if(dfs(root->left, val, answer) or  dfs(root->right, val, answer)) return true;
    answer.pop_back();
    return false;
}

  


int main(){
}
