// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]
 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = nums.size();
        int f = -1, l = -1;
        
        for (int i = 0; i < s; i++) {
            for (int j = i + 1; j < s; j++) {
                if (nums[i] + nums[j] == target) {
                    f = i;
                    l = j;
                    break;
                }
            }
            if (f != -1 && l != -1) {
                break;
            }
        }
        
        return {f, l};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target;
    cout << "Enter target: ";
    cin >> target;
    
    Solution ob;
    vector<int> ans = ob.twoSum(nums, target);
    
    if (ans[0] != -1 && ans[1] != -1) {
        cout << "Indices: " << ans[0] << " " << ans[1] << endl;
    } else {
        cout << "No valid pairs found." << endl;
    }
    
    return 0;
}
