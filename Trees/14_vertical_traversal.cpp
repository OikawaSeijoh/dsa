#include<bits/stdc++.h>

using namespace std;


void dfs(TreeNode* root, int col, priority_queue<pair<int,int>>, vector<pair<int,int>>, greater<pair<int,int>>> &minheap){
    if(!root) minheap.push(col, root->val);
    if(root->left) dfs(root->left, col-1, minheap);
    if(root->right) dfs(root->right, col+1, minheap);
}



vector<vector<int>> verticalTraversal(TreeNode* root){
    priority_queue<pair<int,int>>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
    vector<int> answer;
    dfs(root, 0, minheap);

    while(!minheap.empty()){
        int t = minheap.top().first;
        vector<int> ans;
        while(minheap.top.first == t){
            int val = minheap.top().second;
            ans.push_back(val);
            minheap.pop();
        }
        sort(ans.begin(), ans.end());
        answer.push_back(ans);
    }
    return answer;
}


int main(){
}
