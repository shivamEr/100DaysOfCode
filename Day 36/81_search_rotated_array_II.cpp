

// LINK :  https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int left =0;
        int right = n-1;
        // Binary search ka use hoga same, sorted array 1 jaisa
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==target) return true;

            // Jab sabhi ka values same hoga (edge case hai)
            if(nums[left]==nums[mid]&& nums[mid]==nums[right]){
                left++;
                right--;
            }
            // check kar left side sorted hai kya
            else if(nums[mid]>=nums[left]){
                // agar ha, to check esme target exist karta hai kya
                if(nums[left]<=target && nums[mid]>=target){
                    right = mid-1;
                }
                else left = mid+1;
            }
            // nhi to, right side sorted hoga
            else{
                // check kar right side me target exist karta hai kya
                if(nums[mid]<=target && nums[right]>=target){
                    left = mid+1;
                }
                else right = mid -1;
            }
        }
        // Ab tak target nhi mila to eska mtlab nhi hai
        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 0, 3, 5, 10, 2};
    int target = 0;
    cout<<s.search(nums, target)<<endl;
    return  0;

}