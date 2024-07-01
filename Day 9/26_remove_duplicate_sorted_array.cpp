// Example 1:

// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i =0;i<nums.size()-1;){
            if(nums[i]==nums[i+1]){
            nums.erase(nums.begin()+i);
            }
            else
            i++;
        }
        return nums.size();
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,2};
    cout<<s.removeDuplicates(nums);
    return 0;

}