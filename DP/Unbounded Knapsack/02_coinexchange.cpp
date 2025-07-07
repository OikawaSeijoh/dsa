#include<bits/stdc++.h>

using namespace std;


int coinexchange(vector<int> coin, int sum){

    int dp[100][100];
    for(int i = 0; i <= coin.size(); i++){
        for(int j = 0; j < sum+1; j++){
            if(j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else if(coin[i-1]<=j)
                dp[i][j] = dp[i-1][j]+dp[i][j-coin[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[coin.size()][sum];
}
int main(){
    int n, sum;
    cin >> n;
    vector<int> coin(n);
    for(int i = 0; i < n; i++)
        cin >> coin[i];
    
    cin >> sum;

    cout << coinexchange(coin, sum);
}