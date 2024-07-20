
// LINK : https://leetcode.com/problems/longest-valid-parentheses/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n<1) return 0;
        stack<int>st;
        st.push(-1); 
        int cnt =0;

        for(int i =0;i<n;i++){
            if(s[i] == '(')  st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else cnt = max(cnt,i-st.top());
            }
        }
        return cnt;
    }
};

int main(){
    Solution s;
    cout<<s.longestValidParentheses(")()())");
    return 0;
}