// Leetcode 222

#include<bits/stdc++.h>


using namespace std;

int countNodes(TreeNode* root) {
    if(!root) return 0;
    int lh = 0, rh = 0;

    TreeNode* left = root;
    TreeNode* right = root;

    while(left){
        left = left->left;
        lh++;
    }
    while(right){
        right = right->right;
        rh++;
    }

    if(lh == rh) return pow(2, lh)-1;
    return 1+countNodes(root->left) + countNodes(root->right);
int main(){
}
