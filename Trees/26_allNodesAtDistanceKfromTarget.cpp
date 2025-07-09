//Leetcode 863
#include<bits/stdc++.h>

using namespace std;


// I am a fucking badass. Did this question with a graph. Most optimised motherfucker!!
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        if(root) q.push(root);
        vector<vector<int>> adjl(501);
        int parent = -1;
        int t;
        while(!q.empty()){
            TreeNode* node = q.front();
            int val = node->val;
            if(node == target) t = val;
            if(node->left){
                q.push(node->left);
                adjl[val].push_back(node->left->val);
                adjl[node->left->val].push_back(val);
            }
            if(node->right){
                q.push(node->right);
                adjl[val].push_back(node->right->val);
                adjl[node->right->val].push_back(val);
            };
            q.pop();
        }
            vector<int> answer;
            vector<int> visited(adjl.size(), 0);
            queue<int> gq;
            int distance = 0;
            gq.push(t);
            visited[t] = 1;
            while(!gq.empty() and distance<=k){
                int size = gq.size();
                while(size--){
                    int gnode = gq.front();
                    gq.pop();
                    if(distance == k) answer.push_back(gnode);
                    for(auto i: adjl[gnode]){
                        if(!visited[i]){
                            gq.push(i);
                            visited[i] = 1;
                    }
                }
            }
                distance++;
        }
        return answer;
    }
}

// My implementation of striver's idea. Also his own fucking implementation. Trash. I am the best.
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        if(root) q.push(root);
        map<TreeNode*, TreeNode*> parent;
        vector<int> answer;
        parent[root]=nullptr;
        while(!q.empty()){
            TreeNode* node = q.front();
            int val = node->val;
            if(node->left){
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right] = node;
            };
            q.pop();
        }
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int distance = 0;
        while(!q.empty() and distance <= k){
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(distance == k) answer.push_back(node->val);

                if(parent[node] and visited.find(parent[node])==visited.end()){
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
                if(node->left and visited.find(node->left) == visited.end()){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right and visited.find(node->right) == visited.end()){
                    q.push(node->right);
                    visited.insert(node->right);
                }
            }
            distance++;
        }
        return answer;
    }
int main(){
}
