#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        
        if(n%2!=0 and x == (n+1)/2)
            cout << -1 << endl;
        else{
            int y = n-x+1;
            int cur = 1;
            for(int i = 1; i <=n; i++){
                if(i==1 or i == n){
                    if(i==1)
                        cout << x << " ";
                    else
                        cout << y << " ";
                }
                else{
                    while(cur== x or cur== y)
                        cur++;
                    
                    cout<< cur << " ";
                    cur++;
                    
                    
                }
            }
        cout << endl;
        }
    }
}