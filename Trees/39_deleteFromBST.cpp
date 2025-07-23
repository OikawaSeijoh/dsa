// Leetcode 450

#include<bits/stdc++.h>

using namespace std;

TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return root;
    if(root->val == key) return joiner(root);
    TreeNode* node = root;
    while(node){
        if(node->val > key){
            if(node->left and node->left->val == key){
                node->left = joiner(node->left);
                return root;
            }
            node = node->left;
        }
        else{
            if(node->right and node->right->val == key){
                node->right = joiner(node->right);
                return root;
            }
            node = node->right;
        }
        
    }    
    return root;
}    
TreeNode* joiner(TreeNode* root){
    if(!root->left) return root->right;
    else if(!root->right) return root->left;
    TreeNode* right = findRightMost(root->left);
    right->right = root->right;
    return root->left;
}

TreeNode* findRightMost(TreeNode* node){
    while(node->right)
        node = node->right;
    return node;       
}
int main(){
}
