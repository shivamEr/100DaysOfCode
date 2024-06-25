// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21
 

// Constraints:

// -231 <= x <= 231 - 1

#include <iostream>
#include <climits>  
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long rem, ans = 0;
        while (x) {
            rem = x % 10;
            ans = ans * 10 + rem;
            x = x / 10;
        }
        if (ans < INT_MIN || ans > INT_MAX)
            return 0;
            
        return ans;
    }
};

int main() {
    Solution solution;
    int num;

    cout << "Enter an integer: ";
    cin >> num;

    int reversedNum = solution.reverse(num);

    if (reversedNum != 0) {
        cout << "Reversed integer: " << reversedNum << endl;
    } else {
        cout << "Reversal resulted in overflow or underflow." << endl;
    }

    return 0;
}
