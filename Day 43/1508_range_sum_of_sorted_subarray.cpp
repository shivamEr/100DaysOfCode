
// Problem Link : https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // size ans vector ke liye
        int s = n*(n+1)/2;
        vector<int>ans(s);
        // index to store sum in ans
        int ind=-1;
        // subArray find krne ke liye
        for(int i =0;i<n;i++){
            // har ek sub array ka sum find karega
            int sum=0;
            for(int j =i;j<n;j++){
                sum+=nums[j];
                ans[++ind] = sum; // assinging to ans
            }
        }
        // sorting kyoki answer me sorted part ka sum chahiye
        sort(ans.begin(),ans.end());
        int maxSum = 0;
        // finding answer b/t left - right index
        for(int i =left-1;i<right;i++){
            // answer 1e9+7 se jayada to mod return krega
            maxSum= (maxSum+ans[i])%1000000007;
        }
        // now , final answer
        return maxSum;
    }
};

int main(){
    Solution s;
    vector<int>nums = {1,2,3,4,5};
    int n = 5, left = 3, right = 7;
    cout<<s.rangeSum(nums,n,left,right)<<endl;
    return 0;
}