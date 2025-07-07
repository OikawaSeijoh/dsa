// Leetcode 110
#include<bits/stdc++.h>

using namespace std;

// This is checking if depth between any two subtrees is greater than 1.
bool flag = true;
int findDepth(TreeNode* root, int depth = 0){
    if(!root) return depth;
    int ldepth = findDepth(root->left, depth+1);
    int rdepth = findDepth(root->right, depth+1);

    if(abs(ldepth-rdepth)>1) flag = false;
    return max(ldepth, rdepth);
}
bool isBalanced(TreeNode* root ){
    findDepth(root);
    return flag;
    
}

// Better way that does not use global fucking variables
int findDepth(TreeNode* root){
        if(!root) return 0;
        int ldepth = findDepth(root->left);
        int rdepth = findDepth(root->right);

        if(ldepth == -1 or rdepth == -1) return -1;
        if(abs(ldepth-rdepth)>1) return -1;
        return 1+max(ldepth, rdepth);
    }
    bool isBalanced(TreeNode* root ){
        int depth = findDepth(root);
        return depth == -1? false: true;
        
    }


int main(){
}
