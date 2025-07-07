#include<bits/stdc++.h>

using namespace std;


int countsubsetsum(vector<int> arr, int n, int sum){
    int dp[n+1][sum+1];

    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < sum+1; j++){
            if(j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j]= 0;
            else if(arr[i-1]<= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][sum];
}



int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int arrsum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arrsum+= arr[i];
        }
    int d;
    cin >> d;
    int t = d+arrsum;
    t = t/2;
    cout << t << endl;
    cout << countsubsetsum(arr, n, t);
}