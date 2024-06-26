// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

// The algorithm for myAtoi(string s) is as follows:

// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.
// Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
// Return the integer as the final result.

#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long ans = 0;
        int sign = 1, i = 0;

        // Skip leading whitespaces
        while (i < s.length() && s[i] == ' ') i++;
        if (i < s.length()) s = s.substr(i);

        // Handle optional sign
        if (s[0] == '-') {
            sign = -1;
            i++;
        } else if (s[0] == '+') {
            i++;
        }

        // Convert digits to integer
        while (i < s.length()) {
            if (!isdigit(s[i])) break;
            ans = ans * 10 + s[i] - '0';
            if (ans * sign > INT_MAX) return INT_MAX;
            if (ans * sign < INT_MIN) return INT_MIN;
            i++;
        }

        return ans * sign;
    }
};

int main() {
    Solution solution;

    // Test cases
    string test1 = "42";
    string test2 = "   -42";
    string test3 = "4193 with words";
    string test4 = "words and 987";
    string test5 = "-91283472332";
    string test6 = "+1";
    string test7 = "   +0 123";

    cout << "Test 1: " << solution.myAtoi(test1) << endl;      // Output: 42
    cout << "Test 2: " << solution.myAtoi(test2) << endl;      // Output: -42
    cout << "Test 3: " << solution.myAtoi(test3) << endl;      // Output: 4193
    cout << "Test 4: " << solution.myAtoi(test4) << endl;      // Output: 0
    cout << "Test 5: " << solution.myAtoi(test5) << endl;      // Output: -2147483648 (INT_MIN)
    cout << "Test 6: " << solution.myAtoi(test6) << endl;      // Output: 1
    cout << "Test 7: " << solution.myAtoi(test7) << endl;      // Output: 0

    return 0;
}
