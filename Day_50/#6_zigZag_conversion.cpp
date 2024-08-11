
// Problem Link : https://leetcode.com/problems/zigzag-conversion/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==s.size() || numRows==1) return s;
        vector<string>ans(numRows);
        int ind=0;
        int inc=1;
        for(int i =0;i<s.size();i++){
          ans[ind]+=s[i];
          // ye up to down ke liye increment me help karega
          if(ind==0) inc =1;
          // ye down to up jane me help karega
          if(ind==numRows-1) inc =-1;

          // increment by above condition
          ind+=inc; 
            
        }
        string res;
        for(auto it:ans){
            cout<<it<<endl;
            res+=it;
        }
        return res;
    }
};

int main(){
    Solution s;
    string str = "PAYPALISHIRING";
    int numRows = 3;
    cout<<s.convert(str,numRows)<<endl;
    return 0;
}

