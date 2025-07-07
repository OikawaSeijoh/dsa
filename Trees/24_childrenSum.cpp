// gfg IsSumProperty question
#include<bits/stdc++.h>

using namespace std;


int isSumProperty(Node *root) {
    if(!root or (!root->left and !root->right)) return 1;
    int leftval = 0;
    int rightval = 0;
    
    if(root->left) leftval=root->left->data;
    if(root->right) rightval = root->right->data;
    
    if(root->data!=leftval+rightval) return 0;
    return isSumProperty(root->left) * isSumProperty(root->right);
}

int main(){
}
