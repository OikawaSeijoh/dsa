//Leetcode 297

#include<bits/stdc++.h>

using namespace std;
string serialize(TreeNode* root){
    string data = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        root = q.front();
        q.pop();
        if(!root) data+="#,";
        else{
            string val = to_string(root->val)+',';
            data+=val;
            q.push(root->left);
            q.push(root->right);
        }
    }
    for(auto i: data)
        cout  << i << " ";
    return data;
}


TreeNode* deserialize(string data) {
    stringstream ss(data);
    string st;
    TreeNode* root = nullptr;
    getline(ss, st, ',');
    if(st == "#") return root;
    root = new TreeNode(stoi(st));
    queue<TreeNode*> q ;
    q.push(root);

    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        getline(ss, st, ',');
        if(st!="#"){
            node->left = new TreeNode(stoi(st));
            q.push(node->left); 
        }
        getline(ss, st, ',');
        if(st!="#"){
            node->right = new TreeNode(stoi(st));
            q.push(node->right);
        }
    }
    return root;
}

int main(){
}
