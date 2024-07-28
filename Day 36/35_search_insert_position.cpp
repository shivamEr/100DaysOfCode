
// LINK : https://leetcode.com/problems/search-insert-position/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int ind =0;
        int left =0,right = n-1;
        while(left<=right){
            // mid nikal lete hai
            int mid = (left+right)/2;
            // agar target mila to return kar le
            if(nums[mid]==target) return mid;
            // current bda hai to aage sab bda hi hoga
            else if(nums[mid]>target) {
                // index store karo kyoki, index target se small hi hoga
                ind = mid;
                right = mid-1;
            }
            // current small hai target se to pichhe sab small hi hoga
            else
             left = mid+1;
        }
        // last index ko check karna jaruri hai
        if(nums[n-1]<target){
            ind = n;
        }
        return ind;
    }
};

int main(){
    Solution s;
    vector<int> v = {1,3,5,6};
    int target = 5;
    cout<<s.searchInsert(v,target)<<endl;
    return 0;
}