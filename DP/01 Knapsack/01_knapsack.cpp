#include<bits/stdc++.h>

using namespace std;


// This is recursive code without memoisation
int knapsack(vector<int> weight, vector<int> value, int w, int n){

    if(w==0 or n==0)
        return 0;
    if(weight[n-1]<=w)
        return max(knapsack(weight, value, w, n-1), value[n-1]+knapsack(weight, value, w-weight[n-1], n-1));
    return knapsack(weight, value, w, n-1);

}

int dp[100][100];
int knapsack_mem(vector<int> weight, vector<int> value, int w, int n){
    if(dp[n][w]!=-1)
        return dp[n][w];
    if(w==0 or n==0)
        return dp[n][w] = 0;
    if(weight[n-1]<=w)
        return dp[n][w] = max(knapsack(weight, value, w, n-1), value[n-1]+knapsack(weight, value, w-weight[n-1], n-1));
    return dp[n][w] = knapsack(weight, value, w, n-1);
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

    cout <<"recurseive without memoisation: " << knapsack(weight, value, w, n) << endl;

    memset(dp, -1, sizeof(dp));
    cout <<"recursive with memoisation: " << knapsack_mem(weight, value, w, n);
}