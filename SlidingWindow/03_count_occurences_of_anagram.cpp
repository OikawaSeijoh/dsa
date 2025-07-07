#include<bits/stdc++.h>

using namespace std;

//  My first attempt
int search(string &pat, string &txt) {
    // code here
    unordered_map<char, int> p;
    for(auto i: pat)
        p[i]++;
    
    unordered_map<char, int> t;
    int k = pat.size();
    int i = 0, j = 0; 
    int count = 0;
    while(j<txt.size()){
        char c = txt[j];
        t[c]++;
        
        if(j-i+1<k)
            j++;
        
        else if(j-i+1==k){

            if(t == p) count++;
            t[txt[i]]--;
            if (t[txt[i]] == 0) t.erase(txt[i]);
            i++;
            j++;        
        }
    }
return count;
    
}

//  AV's approach
int search(string &pat, string&txt){
    unordered_map<char, int> p;
    for(auto i:pat)
        p[i]++;
    
    int count = p.size(), ans = 0;
    int i = 0, j = 0;
    while(j < txt.size()){
        if(p.find(txt[j]) != p.end())
            if(--p[txt[j]] == 0) count--;
        
        if(j-i+1<pat.size())
            j++;
        
        else if(j-i+1==pat.size()){
            if(count == 0)
                ans++;
            if(p.find(txt[i]) != p.end()) 
                if(p[txt[i]]++ == 0)count++;
            
            i++;
            j++;
        }  
    }
    return ans;
}


