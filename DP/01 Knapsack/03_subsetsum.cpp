/*
Given:
- targetsum
- array of elements

To find:
- if the target sum can be achieved using the elements of the array

*/



#include<bits/stdc++.h>

using namespace std;



bool subsetsum(vector<int> arr, int n, int sum){
    if(sum==0)
        return true;
    if(n==0)
        return false;
    if(arr[n-1]<=sum)
        return subsetsum(arr, n-1, sum) or subsetsum(arr, n-1, sum-arr[n-1]);
    return subsetsum(arr, n-1, sum);
}

bool subsetsum(vector<int> arr, int n, int sum){}


int main(){

    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << subsetsum(arr, n, sum);

}