
// Problem Link : https://leetcode.com/problems/permutations/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>&nums,int ind,vector<vector<int>>&ans){
        int n = nums.size();
        if(ind == n-1){
            ans.push_back(nums);
            return;
        }

        // finding diff permutations by swapping and backtracking
        for(int i =ind;i<n;i++){
            swap(nums[i],nums[ind]);
            solve(nums,ind+1,ans);
            // backtracking
            swap(nums[i],nums[ind]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return {nums};
        vector<vector<int>>ans;
        solve(nums,0,ans);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = s.permute(nums);
    for(auto &v : res){
        for(auto &x : v) cout<<x<<" ";
        cout<<endl;
    }
        return 0;
}