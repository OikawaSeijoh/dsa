#include<bits/stdc++.h>

using namespace std;



// My naive approach, check for both paths and till there ancestor is common, keep going down both the paths.
bool dfs(TreeNode* root, TreeNode* t, vector<TreeNode*> &path){
    if(!root) return false;
    path.push_back(root);
    if(root == t) return true;
    if(dfs(root->left, t, path) or dfs(root->right, t, path)) return true;
    path.pop_back();
    return false;

}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> ppath;
    vector<TreeNode*> qpath;
    TreeNode* lca = root;
    if(!root) return nullptr;

    dfs(root, p, ppath);
    dfs(root, q, qpath);

    int i = 0;
    while(i < ppath.size() && i < qpath.size() && ppath[i] == qpath[i]){
        lca = ppath[i];
        i++;
    }
    return lca;
}



// Better optimised approach

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
    if(!root or root == p or root == q) return root;
    TreeNode* left = lca(root->left, p, q);
    TreeNode* right = lca(root->right, p, q);
    
    if(!left) return right;
    else if(!right) return left;
    return root;
}

int main(){
}
