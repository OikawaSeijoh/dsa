#include<bits/stdc++.h>

using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q){
    if(!p and !q) return true;
    else if(p and q){
        if(p->val!=q->val) return false;
        return isSameTree(p->left, q->right) and isSameTree(p->right, q->left);
    }
    return false;
}
bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    return isSameTree(root->left, root->right);
}

int main(){
}
