// URL : https://leetcode.com/problems/maximum-subarray/
// Author : Shivam Kumar

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum =0;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>maxSum) maxSum = sum;
            if(sum<0) sum =0;
        }

        return maxSum;
        
    }
};

int main(){
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<s.maxSubArray(nums);
    return 0;
}