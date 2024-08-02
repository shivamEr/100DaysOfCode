
// lINK : https://leetcode.com/problems/remove-outermost-parentheses/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<string>v;
        int open=0,close =0;
        string temp;
        for(auto it:s){
            if(it=='('){
                open++;
            }
            else close++;
            // it hold current string till condition meet
            temp+=it;
            // jab condition match karega to ek string mil gya
            if(open==close){
                v.push_back(temp);
                open = close =0;
                temp = "";
            }
        }
        string ans;
        for(int i =0;i<v.size();i++){
            // don't add first and last char of each string
            for(int j = 1;j<v[i].size()-1;j++) 
            ans+=v[i][j];
            // cout<<v[i]<<endl;
        }
        return ans;
    }
};

int main(){
    Solution s;
    string str = "(()())(())(()(()))";
    cout<<s.removeOuterParentheses(str)<<endl;
    return 0;
}