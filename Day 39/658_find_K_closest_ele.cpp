
// LINK : https://leetcode.com/problems/find-k-closest-elements/

// An integer a is closer to x than an integer b if:

// |a - x| < |b - x|, or
// |a - x| == |b - x| and a < b

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            // it find a-x and then push it
            pq.push({abs(arr[i]-x),arr[i]});
            // size k se jayada to pop()
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            // store answer from pair of queue.
            ans.push_back(pq.top().second);
            pq.pop();
        }
    // sort answer need in sorted order
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    Solution s;
    vector<int>arr = {1,2,3,4,5};
    int k = 4;
    int x = 3;
    vector<int>ans = s.findClosestElements(arr,k,x);

    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}
