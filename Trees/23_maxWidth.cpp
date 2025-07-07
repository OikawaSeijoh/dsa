#include<bits/stdc++.h>

using namespace std;

// Most optimised
int max(int a, int b) {return a>b? a:b;}
int widthOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0ULL});
    int maxWidth = 0;

    while(!q.empty()){
        unsigned long long start = q.front().second;
        unsigned long long end = q.front().second;
        int size = q.size();
        for(int i = 0; i <size; i++){
            auto [node, index] = q.front();
            q.pop();
            index = index-start;// first one will become 0;
            end = index; // last one will be basically width;

            if(node->left) // we are doing 2i, 2i+i indexing cause the normaliszation is used. Each row will start with 0: 0, 1, 2..., next row will be 0, 1, 2, 3, 4, 5(2i, 2i+1);
                q.push({node->left, 2*index});
            
            if(node->right)
                q.push({node->right, 2*index+1});
            
        }
        maxWidth = max(maxWidth, end+1);
    }
    return maxWidth;
}

// First working solution, not very optimised.
int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;

    map<int, unsigned long long> lc, rc;
    queue<pair<TreeNode*, pair<int, unsigned long long>>> q;
    q.push({root, {0, 0}});

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int level = q.front().second.first;
        unsigned long long col = q.front().second.second;
        q.pop();

        if (lc.find(level) == lc.end()) lc[level] = col;
        else lc[level] = min(lc[level], col);

        if (rc.find(level) == rc.end()) rc[level] = col;
        else rc[level] = max(rc[level], col);

        if (node->left) q.push({node->left, {level + 1, 2 * col + 1}});
        if (node->right) q.push({node->right, {level + 1, 2 * col + 2}});
    }

    unsigned long long width = 0;
    for (auto& [level, leftCol] : lc) {
        unsigned long long rightCol = rc[level];
        width = max(width, rightCol - leftCol + 1);
    }

    return (int)width;
}

int main(){
}
