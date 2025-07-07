//  TO find the first negative number in every window size of k;

#include<bits/stdc++.h>

using namespace std;

// my prefered way
vector<int> firstNegInt(vector<int>& arr, int k) {
    queue<int> q;
    vector<int> ans;
    int i = 0, j = 0;

    while (j < arr.size()) {
        if (arr[j] < 0)
            q.push(arr[j]);
        if (j - i + 1 > k) {
            if (!q.empty() && q.front() == arr[i])
                q.pop();
            i++;
        }
        if (j - i + 1 == k) // This if condition is needed unlike the first question cause ans.push_back is dependent on window size unlike max(sum, maxsum)
            ans.push_back(!q.empty() ? q.front() : 0);
        j++;
    }

    return ans;
}

// AV's way
vector<int> firstNegInt(vector<int>& arr, int k) {
        queue<int> q;
        vector<int> ans;
        
        int i = 0, j = 0;
        
        while(j<arr.size()){
            if(arr[j]<0)
                q.push(arr[j]);
            
            if(j-i+1<k)
                j++;
            
            else if(j-i+1 == k){
                ans.push_back(!q.empty()? q.front(): 0);
                
                if(!q.empty() and q.front() == arr[i])
                    q.pop();
                i++;
                j++;
                
            }
        }
        
        return ans;
    }