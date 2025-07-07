#include<bits/stdc++.h>

using namespace std;

int bs_on_reverse(vector<int> &arr, int k){
    int l = 0;
    int r = arr.size()-1;

    while(l<=r){
        int mid = l+(r-l)/2;
        if(arr[mid] == k) return mid;
        else if(arr[mid]<k) r = mid-1;
        else l = mid+1;
    }
    return -1;
}

int main(){
}
