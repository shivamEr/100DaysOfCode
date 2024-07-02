// Shivam Kumar

// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n = nums1.size();
        int m = nums2.size();
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(nums1[i]);
                    nums2[j]=-1;
                    break;
                }

            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> ans = s.intersect(nums1,nums2);
    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}