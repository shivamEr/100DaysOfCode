// Author : shivam kumar

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.


#include<iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if (strs.empty()) return "";

        for(int i=0;i<strs[0].size();i++){
            bool check = true;
            for(int j =0;j<strs.size()-1;j++){
                if(strs[j][i]!=strs[j+1][i]){
                    check = false;
                    break;
                }
            }
           if(check){
            ans +=strs[0][i];
           }
           else break;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> v = {"flower","flow","flight"};
    cout<<s.longestCommonPrefix(v);
    return 0;
}