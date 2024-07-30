
// LINK : https://leetcode.com/problems/kth-largest-element-in-an-array/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        // return nums[nums.size()-k];

        // min heap jo max ko rear pe  rakhega
        priority_queue<int,vector<int>,greater<int>>pq;

        int s = nums.size();

        for(int i =0;i<s;i++){
            pq.push(nums[i]);
            // agar pq ka size k se bda to pop kar 
            // kyoki hme kth need hai
            if(pq.size()>k){
                pq.pop();
            }
        }
        // ab to top() pe hi answer hoga
        return pq.top();

    }
};

int main(){
    Solution s;
    vector<int> v = {3,2,1,5,6,4};
    int k = 2;
    cout<<s.findKthLargest(v,k)<<endl;
    return 0;
}