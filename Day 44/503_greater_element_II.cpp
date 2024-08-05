

// Problem Link : https://leetcode.com/problems/next-greater-element-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        // for store answer
        vector<int>ans(n);
        // to work as monotonic stack
        stack<int>st;

    // Run n*2 time loop for circular check
        for(int i = n*2-1;i>=0;i--){
            // circular ke liye position find krega 
            int ind = i%n;
            while(!st.empty() && nums[ind]>=st.top()) st.pop();

            ans[ind] = st.empty()?-1:st.top();
            // now push into stack
            st.push(nums[ind]);
        }
        return ans;

    }
};

int main(){
    Solution s;
    vector<int>nums = {1,2,1};
    vector<int>ans = s.nextGreaterElements(nums);
    cout<<"[ ";
    for(auto it:ans) cout<<it<<" ";
    return 0;
}