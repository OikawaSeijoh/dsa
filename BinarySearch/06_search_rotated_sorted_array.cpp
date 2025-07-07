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
int search(vector<int>& nums, int target) {
    int minindex = findmin(nums);
    auto start = nums.begin();
    auto end =  nums.end();
    if(target == nums[minindex]) return minindex;
    else if(target>nums[nums.size()-1]){
        start = nums.begin();
        end = nums.begin()+minindex-1;
    }
    else{
        start = nums.begin()+minindex;
        end = nums.end();
    }
    int answer = lower_bound(start, end, target) - nums.begin();
    return nums[answer]==target?answer:-1;
    
}

int main(){
}
