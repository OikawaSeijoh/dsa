#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int j = 0; j < t; j++){
        int n;
        string s;
        cin >> n;
        cin >> s;
        
        int b = 1;
        for(int i = 0; i < n; i++){
            if(s[i]=='0')
                b= 0;
            if(b == 0)
                cout << "NO" << endl;
            else{
                if(i < n-1)
                    cout << "IDK" << endl;
                else
                    cout << "YES" << endl;
            }
        }
    }
	return 0;
}
