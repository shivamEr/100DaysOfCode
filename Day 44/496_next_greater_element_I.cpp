
// Problem Link : https://leetcode.com/problems/next-greater-element-i/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> NGR(vector<int>nums){
        int n = nums.size();
        vector<int>ans(n,-1);
        stack<int>st;
        st.push(nums[n-1]);

        for(int i =n-2;i>=0;i--){
            while(!st.empty() && nums[i]>=st.top()) st.pop();

            // finding index of next greater
            ans[i] = st.empty()?-1:st.top();
            st.push(nums[i]);
        }
        return ans;

    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        vector<int>ngr = NGR(nums2);

        for(int i =0;i<nums1.size();i++){
            for(int j =0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(ngr[j]);
                    break;
                }
            }
        }
        return ans;
    }
};


int main(){
    Solution s;
    vector<int>nums1 = {4,1,2};
    vector<int>nums2 = {1,3,4,2};
    vector<int>ans = s.nextGreaterElement(nums1,nums2);
    for(auto i:ans) cout<<i<<" ";
    return 0;
}