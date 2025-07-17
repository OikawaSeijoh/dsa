#include<bits/stdc++.h>

using namespace std;



// right most node is always threaded to the root node, not to the right of the root.
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preorder;
    TreeNode* cur = root;

    while(cur){
        if(!cur->left){
            preorder.push_back(cur->val);
            cur = cur->right;
        }

        else{
            TreeNode* prev = cur->left;
            while(prev->right and prev->right != cur)
                prev = prev->right;

            if(!prev->right){
                preorder.push_back(cur->val);
                prev->right = cur;
                cur = cur->left;
            }
            else{
                prev->right = nullptr;
                cur = cur->right;
            }
        }
    }

    return preorder;
}
int main(){
}

