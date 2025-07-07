/*
Given:
- number of elements
- weight array
- value array
- maxweight of knapsack

To find:
- maximum value that the knapsack can hold
*/


#include<bits/stdc++.h>

using namespace std;


int knapsack(vector<int> weight, vector<int> value, int w, int n)
{
    int dp[n+1][w+1];
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < w+1; j++){
            if(i==0 or j == 0)
                dp[i][j] = 0;
            
            else if(weight[i-1]<=j)
                dp[i][j] = max(dp[i-1][j], value[i-1]+dp[i-1][j-weight[i-1]]);
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
    vector<int> weight(n);
    vector<int> value(n);
    int w;
    cin >> w;

    for(int i = 0; i < n; i++)
        cin >> weight[i];
    for(int i = 0; i < n; i++)
        cin >> value[i];

    cout <<"recurseive iterative: \n" << knapsack(weight, value, w, n) << endl;

}