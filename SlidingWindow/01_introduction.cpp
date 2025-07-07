// Problem statement 
// Given:
//     array: [2,3,5,2,9,7,1]
//     int 3
//To find the subarray of lenth 3 with max sum

#include<bits/stdc++.h>

using namespace std;

 int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        int sum = 0;
        int maxsum = 0;
        for(int i = 0; i < arr.size(); i++){
            if(i < k)
                sum+=arr[i];
            else
                sum = sum + arr[i] - arr[i-k];
            maxsum = max(sum, maxsum);
                
        }
        return maxsum;
    }



int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        int sum = 0;
        int maxsum = 0;
        int i = 0, j = 0;

        while(j<arr.size()){
            sum+=arr[j];
            if(j-i+1>k)
                sum-=arr[i++];
            
            maxsum = max(sum, maxsum);
            j++;

        }
        return maxsum;
    }


int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        int sum = 0;
        int maxsum = 0;
        int i = 0, j = 0;

        while(j<arr.size()){
            sum+=arr[j];
            if(j-i+1<k)
                j++;
            else if(j-i+1==k){
                maxsum = max(sum, maxsum);
                sum-=arr[i];
                i++;
                j++;
            }

        }
        return maxsum;
    }



int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(auto &i: arr)
        cin >> i;
    
    for(auto i: arr)
        cout << i << " ";



}