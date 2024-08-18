
// Problem Link : https://leetcode.com/problems/count-and-say/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int n,string s){
        if(n==0) return s;
        string temp;
        int cnt =1;
        char ch=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]==ch){
                cnt++;
            }
            else{
                temp+=(to_string(cnt)+ch);
                ch = s[i];
                cnt=1;
            }
        }
        // cout<<temp<<endl;
        temp+=(to_string(cnt)+ch);
        return solve(n-1,temp);

    }
    string countAndSay(int n) {
        return solve(n-1,"1");
    }
};

int main(){
    Solution s;
    cout<<s.countAndSay(4)<<endl;
    return 0;
}