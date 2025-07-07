#include<bits/stdc++.h> 

using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    vector<vector<int>> answer;
    if(root) q.push(root);
    bool flag = true;
    while(!q.empty()){
        int size = q.size();
        vector<int> ans;
        while(size--){
            root = q.front();
            q.pop();
            ans.push_back(root->val);
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
        if(!flag) reverse(ans.begin(), ans.end());
        answer.push_back(ans);
        flag = !flag;
    }
    return answer;   
}

int main(){
}
