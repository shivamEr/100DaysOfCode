// shivam kumar
// Example 1:

// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
       long int ans =0,t=x;
        if(x<0)return false;
        while(t){
            int r = t%10;
            ans = ans*10+r;
            t/=10;
        }
        if(ans == x)
        return true;
        else 
         return false;
    }
};

int main(){
    Solution s;
    cout<<s.isPalindrome(121)<<endl;
    return 0;
}