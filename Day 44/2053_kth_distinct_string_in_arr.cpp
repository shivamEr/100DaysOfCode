
// Problem Link : https://leetcode.com/problems/kth-distinct-string-in-an-array/description/

// Example:

// Input: arr = ["d","b","c","b","c","a"], k = 2
// Output: "a"
// Explanation:
// The only distinct strings in arr are "d" and "a".
// "d" appears 1st, so it is the 1st distinct string.
// "a" appears 2nd, so it is the 2nd distinct string.
// Since k == 2, "a" is returned. 


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mp;
        // frequency count krega, each string ka
        for(auto it:arr){
            mp[it]++;
        }
        string ans;
       for(int i =0;i<arr.size();i++){
        // check kar freq distinct hai kya
            if(mp[arr[i]] ==1){
                // hai to --k and check, is zero
                if(--k<=0){
                  ans = arr[i];
                  break;
                }
            }
       }
        return ans;
    }
};

int main(){
    Solution s1;
    
}

