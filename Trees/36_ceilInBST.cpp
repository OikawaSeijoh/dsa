#include<bits/stdc++.h>

using namespace std;


int findCeil(Node* root, int input) {
    if(!root) return -1;
    if(root->data == input) return input;
    if(root->data<input) return findCeil(root->right, input);
    int leftceil = findCeil(root->left, input);
    return leftceil>=input? leftceil: root->data;
    
}

int findCeil(Node* root, int input){
    int ceil = -1;
    while(root){
        if(root->data == input) return input;
        if(root->data < input) root = root->right;
        else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}
