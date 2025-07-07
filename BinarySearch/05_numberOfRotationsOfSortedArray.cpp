#include<bits/stdc++.h>

using namespace std;

int findmin(vector<int> &nums){
    int l = 0;
    int r = nums.size()-1;

    while(l<r){
        if(nums[l]<=nums[r]) return l;
        int mid = l+(r-l)/2;
        if(nums[mid]> nums[r])
            l = mid+1;
        else
            r = mid;
    }
    return l;
}
int main(){
}
