
// LINK : https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  // function to find beauty of substring
    int findBeauty(vector<int>beauty){
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto it:beauty){
           if(it!=0){
            if(it<mini){
                mini = it;
            }
            if(it>maxi){
                maxi = it;
            }
           }
        }
        return maxi-mini;
    }
    int beautySum(string s) {
        // ye sabhi beauty ko hold karega
        int ans = 0;
        for(int i =0;i<s.size();i++){
            // frequency store karega
            vector<int>beauty(26,0);
            for(int j = i;j<s.size();j++){
                // increament of frequency
                beauty[s[j]-'a']++;
                ans = ans + findBeauty(beauty);
            }
        }
        return ans;
    }
};


int main(){
    Solution obj;
    string s = "aabcb";
    cout<<obj.beautySum(s)<<endl;
    return 0;
}