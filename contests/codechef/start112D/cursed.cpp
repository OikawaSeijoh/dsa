#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int j = 0; j < t; j++){
    	int n;
    	cin >> n;
    	vector<int> arr(n);
    	for(int i = 0; i < n; i++)
    	    cin >> arr[i];
    	sort(arr.begin(), arr.end());
    	int l = 0; 
    	int r = n-1;
    	int sum = 0;
    	vector<int> ans(n);
    	
    	for(int i = 0; i < n; i++){
    	    if(sum<arr[i]){
    	        ans[l] = arr[i];
    	        l++;
    	        sum+=arr[i];
    	        
    	    }
    	    else{
    	        ans[r]=arr[i];
    	        r--;
    	    }
    	}
    	
    	cout << l << endl;
    	for(int i = 0; i < n; i++)
    	    cout << ans[i] << " ";
    	cout << endl;
    }
}