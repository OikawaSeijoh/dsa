#include<bits/stdc++.h>

using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p and !q) return true;
    else if(p and q){
        if(p->val!=q->val) return false;
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
    return false;
}

int main(){
}
