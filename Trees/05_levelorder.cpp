#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    vector<vector<int>> answer;
    if(root) q.push(root);
    while(!q.empty()){
        vector<int> ans;
        int size = q.size();
        while(size--){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        answer.push_back(ans);
    }

    return answer;
}

int main(){
}
