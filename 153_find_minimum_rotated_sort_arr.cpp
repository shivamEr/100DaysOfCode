

// Problem Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int lo=0,hi = n-1;
        int mini = INT_MAX;
        while(lo<=hi){
            // mid index ko find kar
            int mid = (lo+hi)/2;

            // check agar left part sort hai to curr min value (lo) index pe hoga and move right
            if(arr[mid]>=arr[lo]){
                mini = min(mini,arr[lo]);
                lo = mid+1;

            }
            // check agar right part sort hai to curr mini value (mid) index and move left
            else{
                mini = min(mini,arr[mid]);
                hi = mid - 1;
            }
        }
     return mini;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    cout<<obj.findMin(arr)<<endl;
    return 0;
}