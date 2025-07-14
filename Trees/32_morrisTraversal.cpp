#include<bits/stdc++.h>

using namespace std;


// Morris traversal
vector<int> getInorder(TreeNode* root){
    vector<int> inorder;
    TreeNode* cur = root;
    while(cur){
        if(!cur->left){
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        else{
            TreeNode* prev = cur->left;
            while(prev->right and prev->right!= cur)
                prev = prev->right;
            if(!prev->right){
                prev->right = cur;
                cur = cur->left;
            }
            else{
                prev->right = nullptr;
                inorder.push_back(cur->val);
                cur = cur->right;
            }    
        }
    }
    return inorder;
}

int main(){
}
