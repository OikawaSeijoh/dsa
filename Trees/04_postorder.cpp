#include<bits/stdc++.h>

using namespace std;

// Recursive
vector<int> answer;
vector<int> postorderTraversal(TreeNode* root) {
    if(!root) return answer;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    answer.push_back(root->val);

    return answer;
    
}

// Iterative two stacks
vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> stackone;
    stack<TreeNode*> stacktwo;

    if(root) stackone.push(root);
    while(!stackone.empty()){
        TreeNode* node = stackone.top();
        stackone.pop();

        stacktwo.push(node);
        if(node->left) stackone.push(node->left);
        if(node->right) stackone.push(node->right);
    }

    vector<int> answer;
    while(!stacktwo.empty()){
        answer.push_back(stacktwo.top()->val);
        stacktwo.pop();
    }
    return answer;
}

// Iterative single stack my approach
vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> stackone;
    vector<int> answer;
    if(root) stackone.push(root);
    while(!stackone.empty()){
        TreeNode* node = stackone.top();
        stackone.pop();
        answer.push_back(node->val);
        if(node->left) stackone.push(node->left);
        if(node->right) stackone.push(node->right);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}


// Iterative truly single stack approach
vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> stackone;
    vector<int> answer;
    TreeNode* curr = root;
    TreeNode* temp = NULL;

    while(curr or !stackone.empty()){
        if(curr){
            stackone.push(curr);
            curr = curr->left;
        }

        else{
            temp = stackone.top()->right;
            if(temp)
                curr = temp;
            else{
                temp = stackone.top();
                answer.push_back(temp->val);
                stackone.pop();

                while(!stackone.empty() and temp == stackone.top()->right){
                    temp = stackone.top();
                    answer.push_back(temp->val);
                    stackone.pop();
                }
            }
            
        }
    }
    return answer;
}
int main(){
}
