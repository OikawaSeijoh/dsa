//LC: 144
#include<bits/stdc++.h>

using namespace std;

vector<int> answer;
//Recursive
vector<int> preorderTraversal(TreeNode* root) {
    if(!root) return answer;
    answer.push_back(root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);

    return answer;
}

//Iterative
vector<int> preorderTraversal(TreeNode* root){
    stack<TreeNode*> st;
    if(root) st.push(root);

    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        answer.push_back(node->val);
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
   return answer;
} 

int main(){}
