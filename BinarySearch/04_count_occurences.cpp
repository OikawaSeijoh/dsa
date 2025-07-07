//Geeks for geeks question 
#include<bits/stdc++.h>

using namespace std;

int countOccurrence(vector<int> &nums, int target){
    int findex = lower_bound(arr.begin(), arr.end(), target)-arr.begin();
    int lindex = upper_bound(arr.begin(), arr.end(), target)- arr.begin();;
    return lindex-findex;
}

int main(){
}
