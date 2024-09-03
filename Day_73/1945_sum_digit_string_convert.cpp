
// Problem Link : https://leetcode.com/problems/sum-of-digits-of-string-after-convert/


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int getLucky(string s, int k) {
        string ans;
        // converting each character to it crosspondance digit;
        for(auto it:s){
            int n = it-96;
            ans+=to_string(n);
        }
        cout<<ans<<endl;
        int num;
        while(k--){
            num=0;
            for(auto it:ans){
                // calculating sum of digit
                num = num + (it-'0');
            }
            // for next iteration
            ans = to_string(num);
        }
        return num;
    }
};

int main(){
    Solution s;
    cout<<s.getLucky("leet1234", 4)<<endl;
    return 0;
}
