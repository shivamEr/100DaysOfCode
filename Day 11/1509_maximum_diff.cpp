// 1509. Minimum differance between largest and smallest value in Three Moves

// Example 1:

// Input: nums = [1,5,0,10,14]
// Output: 1
// Explanation: We can make at most 3 moves.
// In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
// In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
// In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
// After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 1.
// It can be shown that there is no way to make the difference 0 in 3 moves.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        if(n<=4) return 0;
        sort(nums.begin(), nums.end());
        for(int i =0;i<=3;i++){
            ans = min(ans,nums[n-1-3+i]-nums[i]);
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,5,0,10,14};
    cout<<s.minDifference(nums)<<endl;
    return 0;
}