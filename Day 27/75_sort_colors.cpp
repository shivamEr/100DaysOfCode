// LINK : https://leetcode.com/problems/sort-colors/

// Time Complexity : O(n) - The array is traversed twice: once for counting and once for overwriting.
// Space Complexity : O(1) - Uses a fixed amount of extra space.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z,o,t;
        z=o=t=0;

        for(int i =0;i<nums.size();i++){
            if(nums[i]==0)z++;
            else if(nums[i]==1)o++;
            else t++;
        }
        for(int i =0;i<nums.size();i++){
            if(i<z) nums[i]=0;
            else if(i>=z && i<o+z) nums[i]=1;
            else nums[i]=2;
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,0,2,1,1,0};
    s.sortColors(nums);
    for(auto i:nums){
        cout<<i<<" ";
    }
    return 0;
}