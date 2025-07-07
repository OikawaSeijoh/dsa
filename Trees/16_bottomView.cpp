#include<bits/stdc++.h>

using namespace std;

// Same as top view, just dont check for the value being present, this will update the lowest level value
vector<int> bottomView(Node *root) {
    // Your Code Here
    vector<int> answer;
    map<int, int> mymap;
    queue<pair<Node*, int>> q;
    if(root) q.push({root, 0});
    
    while(!q.empty()){
        pair<Node*, int> nobject = q.front();
        q.pop();
        
        mymap[nobject.second] = nobject.first->data;
        if(nobject.first->left) q.push({nobject.first->left, nobject.second-1});
        if(nobject.first->right) q.push({nobject.first->right, nobject.second +1});
        
    }
    
    for(auto i:mymap) answer.push_back(i.second);
    return answer;
    
}

int main(){
}
