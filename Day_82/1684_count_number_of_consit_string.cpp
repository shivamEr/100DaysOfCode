
// Problem Link : https://leetcode.com/problems/count-the-number-of-consistent-strings/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int>hash(26,0);
        for(auto it:allowed){
            hash[it-'a']=1;
        }

        int cnt =0;
        // iterate over the stringj
        for(int i =0;i<words.size();i++){
            int flag = true;
            for(int j =0;j<words[i].size();j++){
                if(hash[words[i][j]-'a']==0) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};

int main(){
    Solution s;
    string allowed = "abc";
    vector<string>words = {"aab","bac","ab","cab","abc"};
    cout<<s.countConsistentStrings(allowed,words)<<endl;
    return 0;
}