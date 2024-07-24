
// LINK : https://leetcode.com/problems/longest-consecutive-sequence/description/

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0; // Jab ye khali hoga, return 0 kar de
        // sort kar lete hai aasani hoga
        sort(nums.begin(),nums.end());
        int maxi = 1; // final answer store karenge, one to hoga hi
        int cnt = 1; // are count karenge

        for(int i=1;i<nums.size();i++){
            // check kar dono  brabar hai kya
            if(nums[i]==nums[i-1]) continue;
            // Agar dono brabar hai to cnt increase hoga
            else if(nums[i]==nums[i-1]+1) cnt++; 
            // ab maxi ko update karne ka bari hai
            else{
                maxi = max(maxi,cnt);
                // again cnt ko 1 kar dete hai aage count karne ke liye
                cnt = 1;
            }
        }
        // all element consicutive bhi to ho sakta hai
        maxi = max(maxi,cnt);
        return maxi;
    }
};

int main(){
    Solution s;
    vector<int> v = {100,4,200,1,3,2};
    cout<<s.longestConsecutive(v)<<endl;
    return 0;
}