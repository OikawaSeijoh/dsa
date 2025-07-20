#include<bits/stdc++.h>

using namespace std;

TreeNode* searchBST(TreeNode* root, int val) {
    if(!root or root->val == val) return root;
    else if(val>root->val) return searchBST(root->right, val);
    else return (searchBST(root->left, val));
}
TreeNode* searchBST(TreeNode* root, int val){
    while(root and root->val!=val)
        root = root->val>val?root->left:root->right;
    return root;
}

int main(){
}
