#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    for(int j = 0; j < t; j++){
        int n;
        cin >> n;
        
    	vector<int> type(n);
    	vector<int> nourishment(n);
    	
    	for(int i = 0; i < n; i++)
    	    cin >> type[i];
    	for(int i = 0; i < n; i++)
    	    cin >> nourishment[i];
    	
    	unordered_map<int,int> ndict;
    	for(int i = 0; i < n; i++)
    	    ndict[type[i]] = 0;
    	for(int i = 0; i < n; i++){
    	    if(ndict[type[i]]<nourishment[i]){
    	        ndict[type[i]] = nourishment[i];
    	    }
    	}
    	int sum = 0;
    	for(auto i:ndict)
    	    sum+=i.second;
    	    
    	cout << sum << endl;
    }
	return 0;

}
