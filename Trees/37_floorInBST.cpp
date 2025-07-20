#include<bits/stdc++.h>

using namespace std;

int floor(Node* root, int x) {
    if(!root) return -1;
    if(root->data == x) return x;
    if(root->data>x) floor(root->left, x);
    int rightfloor = floor(root->right, x);
    return (rightfloor<=x and rightfloor!=-1)? rightfloor:root->data;
}

int floor(Node* root, int x) {
    int floor = -1;
    while(root){
        if(root->data == x) return x;
        if(root->data>x) root = root->left;
        else{
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}
