#include<bits/stdc++.h>

using namespace std;

int mincoinexchange(vector<int> coins, int sum){
    int n = coins.size();

    int dp[n+1][sum+1];

    for(int i = 0; i < n+1; i++){
        for(int j = 0; j<sum+1; j++){
            if(j == 0)
                dp[i][j] = 0;
            else if(i == 0)
                dp[i][j] = INT_MAX -1;
            else if(coins[i-1]<=j)
                dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
        }
    }
}

int main(){

}