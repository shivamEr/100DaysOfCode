// Author : Shivam kumar

// LINK : https://leetcode.com/problems/maximum-score-from-removing-substrings/description/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(string &s,string com, int point){
        stack<char>st;
        int sum =0;
        for(int i =0;i<s.size();i++){
            if(!st.empty() && st.top()==com[0] && s[i]==com[1]){
                st.pop();
                sum+=point;
            }
            else st.push(s[i]);
        }
        s = "";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return sum;
    }
    int maximumGain(string s, int x, int y) {
        int sum =0;
        if(x>y){
            sum = maxScore(s,"ab",x) + maxScore(s,"ba",y);
        }
        else 
            sum = maxScore(s,"ba",y) + maxScore(s,"ab",x);
        return sum;
    }
};

int main(){
    Solution s;
    cout<<s.maximumGain("yabbol",11,2);
    return 0;
}