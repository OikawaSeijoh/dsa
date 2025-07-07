#includ<bits/stdc++.h>

using namespace std;


// Considering only the column with level order, better solution
vector<int> topView(Node *root) {
    // code here
    vector<int> answer;
    map<int, int> mymap;
    queue<pair<Node*, int>> tq;
    if(root) tq.push({root, 0});
    while(!tq.empty()){
        pair<Node*, int> nobject = tq.front();
        tq.pop();
        Node* node = nobject.first;
        int col = nobject.second;
        
        if(mymap.find(col)==mymap.end())
            mymap[col] =  node->data;
        
        if(node->left) tq.push({node->left, col-1});
        if(node->right) tq.push({node->right, col+1});
    }
    
    for(auto i: mymap)
        answer.push_back(i.second);
    return answer;
    
}

// Considering row and column, my first approach, considers row additionally. The check for empty set is very important, cause the values inside it will not be saved in insertion order.
vector<int> topView(Node *root) {
    // code here
    vector<int> answer;
    map<int, map<int, set<int>>> myfuckingdatastructure;
    queue<pair<Node*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while(!q.empty()){
        pair<Node*, pair<int, int>> nobject = q.front();
        q.pop();
        Node* node = nobject.first;
        int column = nobject.second.first;
        int row = nobject.second.second;
        
        if(myfuckingdatastructure[column][row].empty())
        myfuckingdatastructure[column][row].insert(node->data);
        if(node->left) q.push({node->left, {column-1, row+1}});
        if(node->right) q.push({node->right, {column+1, row+1}});
        
    }
    for(auto i: myfuckingdatastructure){
        for(auto j: i.second) {
            answer.push_back(*j.second.begin());
            break;
        }
    }
    return answer;
    
}
