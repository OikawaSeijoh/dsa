#include<bits/stdc++.h>

using namespace std;

// Striver did the samething just different use of left_sum and right_sum. He took each to be the max with 0.
int maxdepthsum(TreeNode* root, int &sum){
    if(!root) return 0;
    int path_sum = 0;

    int left_sum = maxdepthsum(root->left, sum);
    int right_sum = maxdepthsum(root->right, sum);
    sum = max(sum, max(0,left_sum)+max(right_sum, 0)+root->val);
    return root->val+max(max(left_sum, right_sum), 0);

}
int maxPathSum(TreeNode* root) {
    int sum = INT_MIN;
    maxdepthsum(root, sum);
    return sum;
    
}

int main(){
}
