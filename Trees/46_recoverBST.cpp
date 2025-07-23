// Leetcode 99
#include<bits/stdc++.h>

using namespace std;


TreeNode* prev;
TreeNode* first;
TreeNode* second;
TreeNode* middle;
void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);

    if(prev!=nullptr and prev->val >root->val){
        if(first) second = root;
        else{
            first = prev;
            middle = root;
        }
    }
    prev = root;
    inorder(root->right);

}
void recoverTree(TreeNode* root) {
    inorder(root);
    if(second) swap(first->val, second->val);
    else swap(first->val, middle->val);
    return;
}
int main{}
