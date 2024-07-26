
// LINK : https://leetcode.com/problems/subarray-sum-equals-k/description/


// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // map jo frequency ko count karne me madad krega
        unordered_map<int,int>mp;
        mp[0]=1; // initialy 1, when prefixSum - k ==0
        int prefixSum =0 , cnt =0;
        for(int i =0;i<n;i++){
        // current sum batega 
            prefixSum+=nums[i];
        // prefixSum - k == ab tak me so koe bhi prefixSum
            int remove = prefixSum - k;
        // jaha pe bhi remove mile uska frequency ko cnt me bda le
            cnt += mp[remove];
        // hash map apna value increment karle
            mp[prefixSum]++;
        }
        return cnt;
    }
};

int main(){
    Solution s;
    vector<int>nums = {1,2,3};
    int k = 3;
    cout<<s.subarraySum(nums,k);
    return 0;
}
