#include<bits/stdc++.h>


// GFG question
using namespace std;


int minTime(Node* root, int target){

        if(!root) return 0;
    
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> adjl(1e5);
    
        while(!q.empty()){
            Node* node = q.front();
            int value = node->data;
    
            if(node->left){
                adjl[value].push_back(node->left->data);
                q.push(node->left);
                adjl[node->left->data].push_back(value);
            }
            if(node->right){
                adjl[value].push_back(node->right->data);
                adjl[node->right->data].push_back(value);
                q.push(node->right);
            }
            q.pop();
        }
    
        int distance = 0;
        queue<int> gq;
        vector<int> visited(adjl.size(), 0);
        visited[target] = 1;
        gq.push(target);
    
        while(!gq.empty()){
            int size = gq.size();
            while(size--){
                int gnode = gq.front();
                gq.pop();
    
                for(auto i: adjl[gnode]){
                    if(!visited[i]){
                        gq.push(i);
                        visited[i] = 1;
                    }
                }
            }
            distance++;
        }
        return distance-1;
    }

