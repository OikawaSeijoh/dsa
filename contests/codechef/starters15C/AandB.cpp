#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> a(n);
	    vector<int> b(n);
	    
	    for(int i = 0; i < n; i++)
	        cin >> a[i];
	    for(int i = 0; i < n; i++)
	        cin >> b[i];
	    sort(a.begin(), a.end());
	    sort(b.begin(),b.end(), greater<int>());
	    
	    int val = a[0]+b[0];
	    bool flag = 1;
	    for(int i = 0; i < n; i++){
	        if(a[i]+b[i]!=val)
	            flag = 0;
	    }
	    if(flag==0)
	        cout << -1;
	        
	    else{
	        for(int i = 0; i < n; i++)
	            cout << a[i] <<" ";
	        cout << endl;
	        for(int i = 0; i < n; i++)
	            cout <<  b[i] << " ";
	       cout << endl;
	    }
	}
}
