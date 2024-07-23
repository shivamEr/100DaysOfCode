
// LINK : https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

// OPTIMIZE FUNTION WITH 100 BITS : 

// vector<int> rearrangeArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n);
//         int o = 1, e = 0;
//         for(auto i : nums){
//             if(i > 0){
//                 ans[e] = i;
//                 e = e+2;
//             }
//             else{
//                 ans[o] = i;
//                 o = o+2;
//             }
//         }
//         return ans;
//     }

#include<bits/stdc++.h>
using namespace std;

// My Initial Approach
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int>pos((n/2)); // for postive 
        vector<int>neg((n/2)); // for storing negative values
        vector<int>ans(n);  // for final answer

         int minus=0,plus=0; // track indexes of each pos and neg elements
        for(int i =0;i<n;i++){
            if(nums[i]<0) neg[minus++] = nums[i];
            else pos[plus++] = nums[i];
        }
        minus=0,plus=0;
        for(int i =0;i<n;i++){
            if(i%2==0) ans[i] = pos[plus++]; // if even then assing positive element
            else ans[i]= neg[minus++];  // for assinging negative elements
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int>nums = {3,1,-2,-5,2,-4};
    vector<int>ans = s.rearrangeArray(nums);
    for(int i =0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}



