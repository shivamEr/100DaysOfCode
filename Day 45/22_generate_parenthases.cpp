
// Problem Link : https://leetcode.com/problems/generate-parentheses/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int n,int open,int close,string s,vector<string>&ans){
    // jab string s ka size n*2 ho jaye tab push karde (means balanced)
        if(s.size()==n*2){
            ans.push_back(s);
            return;
        }
    //  open parenthase add jab open less hoga n se
        if(open<n){
            solve(n,open+1,close,s+"(",ans);
        }
    // close parenthases add jab open se less hoga (for balanced)
        if(close<open){
            solve(n,open,close+1,s+")",ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        // to store answers 
        vector<string>ans;
        solve(n,0,0,"",ans);
        return ans;
    }
};

int main(){
    Solution s;
    int n;
    cin>>n;
    vector<string>ans=s.generateParenthesis(n);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}