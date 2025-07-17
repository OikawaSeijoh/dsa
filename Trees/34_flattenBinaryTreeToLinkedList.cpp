// leetcode 114
#include<bits/stdc++.h>

using namespace std;

// This is my first approach using morris traversal
void flatten(TreeNode* root) {
    TreeNode* cur = root;
    while(cur){
        if(!cur->left){
            cur = cur->right;
        }
        else{
            TreeNode* prev = cur->left;
            while(prev->right)
                prev = prev->right;
            prev->right = cur->right;
            cur->right = cur->left;
            cur->left = nullptr;
            cur = cur->right;
}


// This can be done via stack using recursion as well
TreeNode* prev = nullptr;
void flatten(TreeNode* root) {
    if(!root) return;
    flatten(root->right);
    flatten(root->left);

    root->right = prev;
    root->left = nullptr;
    prev = root;

}
int main(){}
