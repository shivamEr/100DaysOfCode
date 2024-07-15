
// LINK : https://leetcode.com/problems/reverse-words-in-a-string/

// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        int n = s.size();
        string word = "";
        for(int i =0;i<n;i++){
            if(s[i]!=' ') word+=s[i];
            else{
                if(word.size()>0) st.push(word);
                word = "";
            }
        }
        if(word.size()>0) st.push(word);

        s.clear();
        while(!st.empty()){
            s +=st.top();
            st.pop();
            s+=" ";
        }
        s.pop_back();
        return s;

        
    }
};
int main(){
    Solution s;
    string s1 = "the sky is blue";
    cout<<s.reverseWords(s1);
    return 0;
}