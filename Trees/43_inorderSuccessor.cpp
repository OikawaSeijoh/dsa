#include<bits/stdc++.h>

using namespace std;

// O(H) and O(1) space
Node* successor(Node* root, int key){
    Node* suc = nullptr;
    while(root){
        if(root->data>key){
        suc = root;
        root = root->left;
        }
        else root = root->right;
    }
    return suc;

}

Node* predecessor(Node* root, int key){
    Node* pred = nullptr;
    while(root){
        if(root->data >= key) root = root->left;
        else{
            if(!pred or pred->data<root->data) pred = root;
            root = root->right;
        }
    }
    return pred;
}
vector<Node*> findPreSuc(Node* root, int key) {
    vector<Node*> answer;
    answer.push_back(predecessor(root, key));
    answer.push_back(successor(root, key));
   
    return answer;
 

int main{}
