

// LINK :  https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// DATE :  2022-09-06

// Time Complexity: O(n) - Single pass through the array.
// Space Complexity : O(1) - Only a few extra variables used.

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        for(int i =0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                cnt++;
            }
        }
       return cnt<=1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,4,5,1,2};
    cout<<s.check(nums);
    return 0;
}