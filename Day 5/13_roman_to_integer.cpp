// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

// Example 1:

// Input: s = "III"
// Output: 3
// Explanation: III = 3.
// Example 2:

// Input: s = "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.
// Example 3:

// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


#include<iostream>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        // int num[7] = {1000,500,100,50,10,5,1};
        // string roman = "MDCLXVI";
        int  arr[len];
        for(int i =0;i<s.length();i++){
            switch(s[i]){
                case 'M' : arr[i] = 1000;  break;
                case 'D' : arr[i] = 500; break;
                case 'C' : arr[i] = 100; break;
                case 'L' : arr[i] = 50; break;
                case 'X' : arr[i] = 10; break;
                case 'V' : arr[i] = 5; break;
                case 'I' : arr[i] = 1; break;
            }
        }
        int ans = 0;
        for(int i =0; i<len-1;i++){
            if(arr[i]<arr[i+1]){
                ans = ans - arr[i];
            }
            else
            ans = ans +arr[i];
        }
        return ans+arr[len-1];

    }
};

int main(){
    Solution s;
    string s1 = "MCMXCIV";
    cout<<s.romanToInt(s1);
    return 0;
}