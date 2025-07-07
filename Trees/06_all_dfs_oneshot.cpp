#include<bits/stdc++.h>

using namespace std;

vector<int> oneshotTraversal(TreeNode* root){
    stack<pair<TreeNode*, int>> st;
    if(root) st.push({root, 1});
    vector<int> inorder, preorder, postorder;

    while(!st.empty()){
        pair<TreeNode*, int> node = st.top();
        st.pop();
        if(node.second == 1){
            preorder.push_back(node.first->val);
            node.second++;
            st.push(node);
            if(node.first->left) st.push({node.first->left, 1});
        }
        else if(node.second == 2){
            inorder.push_back(node.first->val);
            node.second++;
            st.push(node);
            if(node.first->right) st.push({node.first->right, 1});
        }
        else
            postorder.push_back(node.first->val);
    }
    
    return preorder;
}
int main(){
}
