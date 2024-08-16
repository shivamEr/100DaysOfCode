

// Problem Link : https://leetcode.com/problems/maximum-distance-in-arrays/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int mini = arr[0][0];
        int maxi = arr[0].back();
        int diff=0;
        for(int i =1;i<arr.size();i++){
            // Check between mini and currMax
            diff = max(diff,abs(arr[i].back()-mini));
            // check between maxi and currMini
            diff = max(diff,abs(arr[i][0]-maxi));
            // finding min
            mini = min(mini,arr[i][0]);
            // finding max
            maxi = max(maxi,arr[i].back());
        }
        return diff;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> arr = {{1,2,3},{4,5},{6,
    7,8,9}};
    cout<<solution.maxDistance(arr)<<endl;
    return 0;

}