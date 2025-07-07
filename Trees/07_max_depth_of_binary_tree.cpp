#include<bits/stdc++.h>

using namespace std;


// Iterative (BFS)
int maxDepth(TreeNode* root) {
    int depth = 0;
    queue<TreeNode*> q;
    if(root) q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            TreeNode* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        depth++;
    }
    return depth;
}

// Recurisive
int maxDepth(TreeNode* root, int depth = 0) {
        if(!root)
            return depth;
        
        return max(maxDepth(root->left, depth+1), maxDepth(root->right, depth+1)); 
}

// Recursive striver: sligtly better
int maxDepth(TreeNode* root){
    if(!root) return 0;
    return 1+max(maxDepth(root-> left), max->depth(root->right));
}
int main(){
}
