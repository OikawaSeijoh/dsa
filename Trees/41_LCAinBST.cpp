#include<bits/stdc++.h>


using namespace std;
// my approach
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int lower = min(p->val, q->val);
    int higher = max(p->val, q->val);
    while(root){
        if(root->val >= lower and root->val<=higher) return root;
        else if(root->val > higher) root = root->left;
        else root = root->right;
    }
    return root;
}
//striver's approach
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return NULL;
    if(root->val < p->val and root->val < q->val) return lowestCommonAncestor(root->right, p, q);
    else if(root->val > p->val and root->val > q->val) return lowestCommonAncestor(root->left, p, q);
    return root;
}
int main(){
}
