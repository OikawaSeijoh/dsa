// GFG question

#include<bits/stdc++.h>

using namespace std;


// Preorder
void recursion(Node* root, int level, vector<int> &answer){
    if(!root) return;
    if(level == answer.size()) answer.push_back(root->data);
    
    recursion(root->left, level+1, answer);
    recursion(root->right, level+1, answer);
    // return answer;
}
vector<int> leftView(Node *root) {
    vector<int> answer;
    if(!root) return answer;
    recursion(root, 0, answer);
    
    return answer;
    
}
// Level order
vector<int> leftView(Node *root) {
    // code here
    vector<int> answer;
    map<int, int> mymap;
    queue<pair<Node*, int>> q;
    
    if(root) q.push({root, 0});
    
    while(!q.empty()){
        Node* node = q.front().first;
        int level = q.front().second;
        q.pop();
        
        if(mymap.find(level)==mymap.end())
            mymap[level] =  node->data;
        
        if(node->left) q.push({node->left, level+1});
        if(node->right) q.push({node->right, level+1});
    }
    
    for(auto i:mymap)
        answer.push_back(i.second);
    return answer;
}


int main(){
}
