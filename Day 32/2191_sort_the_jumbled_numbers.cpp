
// LINK : https://leetcode.com/problems/sort-the-jumbled-numbers/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> pairs; // store karenege mapped number with index
        for(int i = 0;i<nums.size();i++){
            // element ko string me convert kar lete hai
            string num = to_string(nums[i]);
            string s; // mapped number ko store karenege
            // Ab iterate karke mapped kar lete hai
            for(int j = 0;j<num.size();j++){
                s += to_string(mapping[num[j]-'0']); // index conversion
            }
            pairs.push_back({stoi(s),i}); // stoi() string to int convertion

        }
        // Ab sort kar lete hai index pta lag jayega
        sort(pairs.begin(),pairs.end());
        // Ab final answer mil jayega index se
        vector<int>ans;
        for(auto i : pairs){
            ans.push_back(nums[i.second]);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {23,34,12,67,90};
    vector<int> mapping = {8,9,7,6,5,3,0
    ,2,1,4};
    vector<int> ans = s.sortJumbled(mapping,nums);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;

}