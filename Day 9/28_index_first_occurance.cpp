// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.

#include<iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans;
            for(int i =0;i<haystack.length();i++){
            ans = 1;
            for(int j =0;j<needle.length();j++){
                if(haystack[i+j]!=needle[j]){
                ans = -1;
                break;

                }
                
            }
            if(ans!=-1){
            return i;

            }
        }
            return ans;

        
    }
};

int main(){
    Solution s;
    string haystack = "sadbutsad", needle = "sad";
    cout<<s.strStr(haystack,needle);
    return 0;
}