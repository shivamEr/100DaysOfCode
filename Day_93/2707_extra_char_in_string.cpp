
// Problem Link : https://leetcode.com/problems/extra-characters-in-a-string/

class Solution {
public:
    int solve( int i, string&s, unordered_set<string>&st, int &n,unordered_map<int,int>&dp){
        if(i>=n) return 0;
        
        if(dp.find(i)!=dp.end()){
            return dp[i];
        }
        int ans = 1 + solve(i+1, s, st, n,dp);
        
        for(int j = i; j<n; j++){
            string curr = s.substr(i,j-i+1);
            if(st.count(curr)){
                ans = min(ans, solve(j+1, s, st,n,dp));
            }
        }
        dp[i] = ans;
        return ans;
    }
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.size();
        unordered_set<string> st(dict.begin(), dict.end());
        unordered_map<int,int>dp;
        return solve(0, s, st,n,dp);
    }
};