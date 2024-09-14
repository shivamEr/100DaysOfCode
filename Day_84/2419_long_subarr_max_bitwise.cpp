
// Problem Link : https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        int len = 1;
        int cnt = 0;
        // Greater element ko return karega
        int mx = *max_element(arr.begin(),arr.end());

        for(auto it:arr){
            // each time checked mx number equality
            if(it==mx) cnt++;
            else cnt=0;
            // max length bta dega
            len = max(len,cnt);
        }
        return len;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {2,1,2,2,1};
    cout<<obj.longestSubarray(arr)<<endl;
    return 0;
}