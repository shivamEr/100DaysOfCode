// shivam kumar
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false

#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if(len%2!=0) return false;

        stack<char>p;
        for(int i =0;i<len;i++){
            if(p.empty()){
                p.push(s[i]);
            }
            else if((s[i]=='}' && p.top()=='{') 
            || (s[i]== ']' && p.top() =='[' )
            || ( s[i] == ')' && p.top()=='('))
            p.pop();
            else
            p.push(s[i]);
        }
        if(p.empty())
        return true;
        else 
        return false;
    }
};

int main(){
    Solution s;
    string s1 = "{[]}";
    string s2 = "{[}";
    cout<<s.isValid(s1)<<endl;
    cout<<s.isValid(s2)<<endl;
    return 0;

}