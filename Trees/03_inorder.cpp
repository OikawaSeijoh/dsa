#include<bits/stdc++.h>

using namespace std;

vector<int> answer;
//recursive
vector<int> inorderTraversal(TreeNode* root) {
    if(!root)
        return answer;
    inorderTraversal(root->left);
    answer.push_back(root->val);
    inorderTraversal(root->right);

    return answer;
}


//iterative
vector<int> inorderTraversal(TreeNode* root){
    stack<TreeNode*> st;
    TreeNode* node = root;

    while(true){
        if(node){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            answer.push_back(node->val);
            node = node->right;
        }
    }
    return answer;

}

int main(){

