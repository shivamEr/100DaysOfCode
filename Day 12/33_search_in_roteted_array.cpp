// Shivam -> 04-07-2024
// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left =0, right = nums.size()-1;

        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>=nums[left]){
                if(nums[mid]>=target && nums[left]<=target){
                    right = mid -1;
                }
                else left = mid+1;
            }
            else{
                if(nums[mid]<=target && nums[right]>=target){
                    left = mid+1;
                }
                else right = mid -1;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout<<s.search(nums, target)<<endl;
    return 0;
}