#include<bits/stdc++.h>

using namespace std;

int binaryserach(vector<int> arr, int k){
    int l = 0;
    int r = arr.size()-1;
    
    while(l<r){
        int mid = r-(r-l)/2;
        if(arr[mid]==k)
            return mid;
        else if(arr[mid]<k) l=mid+1;
        else r = mid-1;
    }
    return l;
}
int main(){
}
