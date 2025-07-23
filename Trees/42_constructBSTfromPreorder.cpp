//leet code 1008
#include<bits/stdc++.h>


using namespace std;

// My first approach
TreeNode* bstFromPreorder(vector<int>& preorder) {
    if(!preorder.size()) return nullptr;
    int i = 0;
    TreeNode* root = new TreeNode(preorder[i]);
    i++;
    for(i; i< preorder.size(); i++){
        int val = preorder[i];
        TreeNode* cur = root;
        while(true){
            if(cur->val>val){
                if(cur->left) cur = cur->left;
                else{
                    cur->left = new TreeNode(val);
                    break;
                }
            }
            else{
                if(cur->right) cur = cur->right;
                else{
                    cur->right = new TreeNode(val);
                    break;
                }
            }
        } 
    }
    return root;
}

// Approach 2: sort preorder for inorder, make tree from inorder, preorder
 TreeNode* BuildTreefromPreIn(vector<int> &preorder, vector<int> &inorder, int prestart, int preend, int instart, int inend, unordered_map<int, int> inmap){
    if(prestart>preend or instart > inend) return nullptr;
    TreeNode* root = new TreeNode(preorder[prestart]);
    int rootindex = inmap[root->val];
    int leftsize = rootindex - instart;
    root->left = BuildTreefromPreIn(preorder, inorder, prestart+1, prestart+leftsize, instart, rootindex-1, inmap);
    root->right = BuildTreefromPreIn(preorder, inorder, prestart+leftsize+1, preend, rootindex+1, inend, inmap); 
    return root;
}
TreeNode* bstFromPreorder(vector<int> & preorder){
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());
    unordered_map<int, int> inmap;
    for(int i = 0; i < inorder.size(); i++){
        inmap[inorder[i]] = i;
    }

    return BuildTreefromPreIn(preorder,inorder, 0, preorder.size()-1, 0, preorder.size()-1, inmap);
} 

// Approach 3: O(N)
TreeNode* maketree(vector<int> &preorder, int &i, int ubound){
    if(i>=preorder.size() or preorder[i] >= ubound) return nullptr;
    TreeNode* root = new TreeNode(preorder[i]);
    i++;
    root->left = maketree(preorder, i, root->val);
    root->right = maketree(preorder, i, ubound);
    return root;

}
TreeNode* bstFromPreorder(vector<int> & preorder){
    int i = 0;
    return maketree(preorder, i, INT_MAX);
}
int main(){
} 
