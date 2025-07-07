/*
Given an array and a target sum, return the number of subsets that add up to the target sum
*/


/*
Given an array and a target sum, return the number of subsets that add up to the target sum
*/


#include<bits/stdc++.h>

using namespace std;


//  Recursive
int countsubsetsum(vector<int> arr, int n, int sum){
    if(sum == 0)
        return 1;
    else if(n==0)
        return 0;

    else if(arr[n-1]<= sum)
        return countsubsetsum(arr, n-1, sum-arr[n-1])+countsubsetsum(arr, n-1, sum);
    else
        return countsubsetsum(arr, n-1, sum);
}

//  Iterative
int countsubsetsum(vector<int> arr, int n, int sum){
    int dp[n+1][sum+1];
    
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < sum+1; j++){
            if(j == 0)
                dp[i][j] = 1;
            else if(i == 0)
                dp[i][j] = 0;
            else if(arr[i-1]<= j)
                dp[i][j] = dp[i-1][j]+dp[i-1][j-arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
            cout << dp[i][j] << " ";
        }
        
        cout << endl;
    }
    return dp[n][sum];
}

int main(){
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << countsubsetsum(arr, n, sum);
    
}