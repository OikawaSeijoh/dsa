#include<bits/stdc++.h>

using namespace std;

int maxDepth(TreeNode* root, int &diameter){
    if(!root) return 0;
    int ldepth = maxDepth(root->left, diameter);
    int rdepth = maxDepth(root->right, diameter);

    diameter = max(diameter, ldepth+rdepth);
    return 1+max(ldepth, rdepth);
}
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    maxDepth(root, diameter);
    return diameter;
}

int main(){
}
