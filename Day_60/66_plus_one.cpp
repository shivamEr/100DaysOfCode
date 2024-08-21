

// Problem Link : https://leetcode.com/problems/plus-one/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int>ans;
        int non_zero =0;
        // remove leading zero
        while(digits[non_zero]==0 && non_zero<n-1) non_zero++;

        int num=1;
        for(int i=n-1;i>=non_zero;i--){
            num+=digits[i];
            ans.push_back(num%10);
            num/=10;
        }
        if(num!=0) ans.push_back(num);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> digits = {1,2,3};
    vector<int> ans = s.plusOne(digits);
    for(auto i:ans) cout<<i<<" ";
    return 0;
}

