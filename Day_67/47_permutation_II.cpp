
// Problem Link : https://leetcode.com/problems/permutations-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>&nums,int ind,vector<vector<int>>&ans){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }

        // map for finding duplicate num
        unordered_map<int,int>mp;
        for(int i =ind;i<nums.size();i++){
            // skip duplicate permutation
            if(mp.find(nums[i])!=mp.end()) continue;

            mp[nums[i]]++;
            swap(nums[i],nums[ind]);
            solve(nums,ind+1,ans);
        // backtracking 
            swap(nums[i],nums[ind]);
            
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        if(nums.size()<=1) return ans;
        // sort for the skiping the duplicates combination
        sort(nums.begin(),nums.end());
        solve(nums,0,ans);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int>nums = {1,1,2};
    vector<vector<int>>ans = s.permuteUnique(nums);
    
    for(auto it:ans){
        for(auto it2:it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}