// shivam kumar
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = "2"
// Output: ["a","b","c"]


#include<iostream>
#include<vector>
// #include<string>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()<1) 
        return {};
        string s[] ={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans={""};
        // vector<string>temp;
        for (char digit : digits) {
            string charS = s[digit - '2'];
            vector<string> tempCom;
            for (string a : ans) {
                for (char ch : charS) {
                    tempCom.push_back(a + ch);
                }
            }
            ans = move(tempCom);
        }
        return ans;
    }
};

int main(){
    Solution s;
    string digits = "23";
    vector<string>ans = s.letterCombinations(digits);
    for (string a : ans) {
        cout<<a<<" ";
    }
}

