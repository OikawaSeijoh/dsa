// Gfg Question, leetcode version is only for premium

#include<bits/stdc++.h>

using namespace std;

void dfs(Node* root, vector<int> &answer){
    if(!root->left and !root->right) answer.push_back(root->data);
    if(root->left) dfs(root->left, answer);
    if(root->right) dfs(root->right, answer);
    
}
vector<int> boundaryTraversal(Node *root) {
    vector<int> answer;
    Node* node = root;
    if(!node) return answer;
    answer.push_back(root->data);
    if(!root->left and !root->right) return answer;
    
    node = node->left;
    while(node){
        if(node->left||node->right) answer.push_back(node->data);
        if(node->left) node = node->left;
        else node = node->right;
    }
    dfs(root, answer);
    int rightsize = answer.size();
    
    node = root->right;
    while(node){
        if(!node->right and !node->left) break;
        answer.push_back(node->data);
        if(node->right) node = node->right;
        else node = node->left;
        
    }
    reverse(answer.begin()+rightsize, answer.end());
    return answer;
}

int main(){
}k
