
// Problem Link : https://leetcode.com/problems/longest-palindromic-substring/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<=1) return s;
        int maxlen = 1;
        // ye longest plindrom ka start and end index btayega
        int start=0,end=0;
        // for DP we have to create 2D bool array
        vector<vector<bool>>dp(n,vector<bool>(n,0));
        for(int i =0;i<n;i++){
            // single digit always palindrom
            dp[i][i] = 1;
            for(int j =0;j<i;j++){
                if(s[j]==s[i] && (i-j<=2 || dp[j+1][i-1])){
                    // substirng j..i as palindrom
                    dp[j][i] = 1;
                    // check current palindrom ka length bda hai maxlen se
                    if(i-j+1>maxlen){
                        maxlen = i-j+1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        // cout<<ans<<endl;
        return s.substr(start,end-start+1);
    }
};

int main(){
    Solution obj;
    string s = "babad";
    cout<<obj.longestPalindrome(s)<<endl;
    return 0;
}