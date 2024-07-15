
// LINK :  https://leetcode.com/problems/removing-stars-from-a-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        st.push(s[0]);
        for(int i =1;i<s.size();i++){
            if(s[i]=='*'){
                if(!st.empty()) st.pop();
            }
            else st.push(s[i]);
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main(){
    Solution s;
    cout<<s.removeStars("leet**cod*e");
    return 0;
}