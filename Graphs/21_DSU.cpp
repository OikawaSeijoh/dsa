#include<bits/stdc++.h>

using namespace std;

class DSU{
    vector<int> parent;
    vector<int> rank;
    public:
        
        DSU(int n){
            parent.resize(n);
            rank.resize(n, 1_

        int find(int a){
            if(a==parent[a])    
                return parent[a];
            return parent[a] = find(parent[a]);
        }


        void union_set(int a, int b){
            int parent_a = find(a);
            int parent_b = find(b);
            if(parent_a == parent_b) return;
            if(rank[parent_a]>rank[parent_b]){
                rank[parent_a]+=rank[parent_b];
                parent[parent_b] = parent_a;
            }

            else{
                rank[parent_b]+=rank[parent_a];
                parent[parent_a] = parent_b;
            
            }
        }      
};
int main(){

}
