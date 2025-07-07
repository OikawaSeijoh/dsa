#include<bits/stdc++.h>

using namespace std;


int knapsack(vector<int> arr, int n, int w){

    int dp[n+1][w+1];

    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < w+1; j++){
            if(i == 0 or j == 0)
                dp[i][j] = 0;
            else if(arr[i-1]<=j)
                dp[i][j] = max(dp[i-1][j], arr[i-1]+ dp[i-1][j-arr[i-1]]);
            else 
                dp[i][j] = dp[i-1][j];
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][w];
}

int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    int arrsum = 0;


    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arrsum += arr[i];
    }
    int s1 = knapsack(arr, n, arrsum/2);
    cout << arrsum - 2*  s1;
    

    
}