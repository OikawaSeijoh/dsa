// Leetcode 105
#include<bits/stdc++.h>

using namespace std;

// Using map O(N)
TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder, int prestart, int preend, int instart, int inend, unordered_map<int, int> &inmap){
    if(instart>inend or prestart>preend) return nullptr;
    TreeNode* root = new TreeNode(preorder[prestart]);
    int rootind = inmap[root->val];
    int leftsize = rootind-instart;
    root->left = buildTree(preorder, inorder, prestart+1, prestart+leftsize, instart, rootind-1, inmap);
    root->right = buildTree(preorder, inorder, prestart+leftsize+1, preend, rootind+1, inend, inmap);
    return root;
}


TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder){
    unordered_map<int, int> inmap;
    for(int i = 0; i < inorder.size(); i++){
        inmap[inorder[i]] = i;
    }

    return buildTree(preorder, inorder, 0, inorder.size()-1, 0, inorder.size()-1, inmap);
}
// My first approach. O(n2)
TreeNode* btree(vector<int> &preorder, vector<int> &inorder, int &p, int instart, int inend){
    if(instart>inend or p>= preorder.size()) return nullptr;
    TreeNode* root = new TreeNode(preorder[p]);
    p++;
    int i ;
    for(i = instart ; i < inend; i++)
        if(inorder[i]==root->val) break;

    root->left = btree(preorder, inorder, p, instart, i-1);
    root->right = btree(preorder, inorder, p, i+1, inend);
    return root;
    }
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(!inorder.size()) return nullptr;
    int p = 0;
    return btree(preorder, inorder, p, 0, inorder.size()-1);
    }

int main(){
}
