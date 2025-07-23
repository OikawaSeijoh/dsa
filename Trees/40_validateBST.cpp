// Leetcode 98

#include<bits/stdc++.h>

using namespace std;

// My first approach, check if inorder is sorted.
void inorder(TreeNode* root, vector<int> &answer){
        if(!root) return;
        inorder(root->left, answer);
        answer.push_back(root->val);
        inorder(root->right, answer);
        return;
    }
bool isValidBST(TreeNode* root) {
    if(!root) return true;
    vector<int> answer;
    inorder(root, answer);
    int prev = answer[0];
    for(int i = 1; i < answer.size(); i++){
        if(prev>=answer[i]) return false;
        prev = answer[i];
    }
    return true;
}


// striver's approach
bool validate(TreeNode* root, long long mrange, long long maxrange){
    if(!root) return true;
    if(root->val<=mrange or root->val>=maxrange) return false;
    return validate(root->left, mrange, root->val) and validate(root->right, root->val, maxrange);
}
bool isValidBST(TreeNode* root) {
    if(!root or (!root->left and !root->right)) return true;
    return validate(root, LLONG_MIN, LLONG_MAX);
    
}
