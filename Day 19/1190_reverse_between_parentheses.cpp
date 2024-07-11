// URL : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/

#include<iostream>
using namespace std;

class Solution {
public:
    string findReverseAns(string s){
        string ans;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='('|| s[i]==')') continue;
            else ans = ans+s[i];
        }
        return ans;
    }
    void reverseBetween(string &s,int i,int j){
         int left =i+1, right = j-1;
        while(left<=right){
            if(s[left]=='(' && s[right]==')') left++, right --;
            else if(s[left]=='(') left++;
            else if(s[right]==')') right--;
            else{
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }
    }
    string reverseParentheses(string s) {
        stack<int>st;
       for(int i =0;i<s.size();i++){
        if(s[i]=='(') st.push(i);
        else if(s[i]==')'){
            reverseBetween(s,st.top(),i);
            st.pop();
        }
       }
       return findReverseAns(s);
    }
};

int main(){
    Solution s;
    string s = "(u(love)i)";
    cout<<s.reverseParentheses(s);
    return 0;
}