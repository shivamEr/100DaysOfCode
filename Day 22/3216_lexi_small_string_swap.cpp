

// CONTEST 406 : 14-07-2024
// liNK : https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getSmallestString(string s) {
        int n =s.size();
        for(int i =0;i<n-1;i++){
            if(s[i]%2==s[i+1]%2 && s[i]>s[i+1]){
            swap(s[i],s[i+1]);
             break;
            } 
        }
        return s;
    }
};

int main(){
    Solution s;
    string s = "aaiioo";
    cout<<s.getSmallestString(s);
    return 0;
}