#include<bits/stdc++.h>

using namespace std;



void makeChildrenSum(){
    if(!root) return;
    int child = 0;
    if(root->left) child+=root->left->val;
    if(root->right) child+=root->right->val;
    if(root->val <= child) root->val = child;

    else{
        if(root->left) root->left->val = root->val;
        else if(root->right) root->right->val = root->val;
    }

    makeChildrenSum(root->left)l
    makeChildrenSum(root->right);

    int total = 0;
    if(root->left) total+=root->left->val;
    if(root->right) total+=root->righ->val;
    if(root->left or root->right) root->val = total;
    return;
}
