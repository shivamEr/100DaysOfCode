

// Problem Link : https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());

        for(int i =0;i<arr.size();i++){
            if(arr[i]!=target[i]) return false;
        }
        return true;
    }
};

int main(){
    Solution solution;
    vector<int> target = {1,2,3,4,5};
    vector<int> arr = {1,2,3,4,5};
    cout<<solution.canBeEqual(target,arr)<<endl;
    return 0;
}