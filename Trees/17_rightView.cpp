// Leetcode: 199

#include<bits/stdc++.h>

using namespace std;

// Striver's recursive method, less code same complexity
void dfs(TreeNode* root, int level, vector<int> &answer){
    if(!root) return;
    if(answer.size()==level) answer.push_back(root->val);
    dfs(root->right, level+1, answer);
    dfs(root->left, level+1, answer);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> answer;
    if(!root) return answer;
    dfs(root, 0, answer);
    return answer;
    
}

// Level order
vector<int> rightSideView(TreeNode* root) {
    vector<int> answer;
    map<int, int> mymap;

    queue<pair<TreeNode*, int>> q;
    if(root) q.push({root, 0});

    while(!q.empty()){
        TreeNode* node = q.front().first;
        int level = q.front().second;
        q.pop();
        mymap[level] =  node->val;

        if(node->left) q.push({node->left, level+1});
        if(node->right) q.push({node->right, level+1});
    }

    for(auto i: mymap)
        answer.push_back(i.second);
    
    return answer;
    
}

int main(){
}
