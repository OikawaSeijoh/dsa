#include<bit/stdc++.h>


using namespace std;

class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        add_all_left(root);
    }
    void add_all_left(TreeNode* root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if(node->right)
            add_all_left(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
int main(){
}
