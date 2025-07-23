#include<bits/stdc++.h>

using namespace std;
class BSTIterator{


};
class BSTIterator{
    public:
        stack<TreeNode*> nstack;
        stack<TreeNode*> bstack;
        BSTIterator(TreeNode* root){
            add_all_left(root);
            add_all_right(root);
        }
        void add_all_left(TreeNode* root){
            while(root){
                nstack.push(root);
                root= root->left;
            }
        }
        void add_all_right(TreeNode* root){
            while(root){
                bstack.push(root);
                root = root->right;
            }
        }

        int next(){
            TreeNode* node = nstack.top();
            nstack.pop();
            if(node->right) add_all_left(node->right);
            return node->val;
        }

        int before(){
            TreeNode* node = bstack.top();
            bstack.pop();
            if(node->left) add_all_right(node->left);
            return node->val;
        }

        bool hasnext(){
            return !nstack.empty();
        }
        bool hasbefore(){
            return !bstack.empty();
        }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator bst = BSTIterator(root);
        if(!bst.hasnext() or !bst.hasbefore()) return false;
        int left = bst.next();
        int right = bst.before();
        while(left<right){
            int sum = left+right;
            if(sum==k) return true;
            else if(sum<k){
                if(bst.hasnext()) left = bst.next();
                else break;
            }
            else{
                if(bst.hasbefore()) right = bst.before();
                else break;
            }
        }
        return false;
    }
};
int main(){
}
