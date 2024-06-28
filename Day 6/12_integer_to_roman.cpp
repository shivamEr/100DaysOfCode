// Seven different symbols represent Roman numerals with the following values:

// Symbol	Value
// I	1
// V	5
// X	10
// L	50
// C	100
// D	500
// M	1000

// Example 1:

// Input: num = 3749

// Output: "MMMDCCXLIX"

// Explanation:

// 3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
//  700 = DCC as 500 (D) + 100 (C) + 100 (C)
//   40 = XL as 10 (X) less of 50 (L)
//    9 = IX as 1 (I) less of 10 (X)
// Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places

#include<iostream>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string ans[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int arr[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string s;
        for(int i =0;i<13;i++){
            while(arr[i]<=num){
                s = s+ans[i];
                num = num - arr[i];
            }
        }
        return s;
    }
};
int main(){
    Solution s;
    cout<<s.intToRoman(1994);
    return 0;

}