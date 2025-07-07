#include<bits/stdc++.h>

using namespace std;


int unboundedknapsack(vector<int> weight, vector<int> value, int n, int w){
    int dp[n+1][w+1];

    for(int i = 0; i < n+1;i++){
        for(int j = 0; j < w+1; j++){
            if(i == 0 or j == 0)
                dp[i][j] = 0;
            else if(weight[i-1]< j)
                dp[i][j] = max(dp[i-1][j], dp[i][j-weight[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][w];
}



int main(){
    int n;
    cin >> n;
    vector<int> weight(n);
    vector<int> value(n);

    for(int i = 0; i < n; i++)
        cin >> weight[i];
    
    for(int i = 0; i < n; i++)
        cin >> value[i];
    
    int w;
    cin >> w;

    cout << unboundedknapsack(weight, value, n, w)
}