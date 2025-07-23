// Leetcode 701
#include<bits/stdc++.h>

using namespace std;

TreeNode* insertIntoBST(TreeNode* root, int val){
    if(!root){
        root = new TreeNode(val);
        return root;
    }
    TreeNode* cur = root;
    while(cur){
        if(cur->val < val){
            if(cur->right) cur = cur->right;
            else{
                cur->right = new TreeNode(val);
                return root;
            }
        }
        else{
            if(cur->left) cur = cur->left;
            else{
                cur->left = new TreeNode(val);
                return root;
            }
        }
    }
    return root;
}
