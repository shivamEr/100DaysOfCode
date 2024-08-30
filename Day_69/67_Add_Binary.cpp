
// Problem Link : https://leetcode.com/problems/add-binary/description/


class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size() - 1; 
        int n = b.size() - 1; 
        string ans; 
        // carry ko track karne ke liye
        int carry = 0; 

        while (m >= 0 || n >= 0 || carry) {
            // agar a me digits bachi hai toh usko add karo
            if (m >= 0) {
                carry += a[m] - '0';
                m--;
            }
            // agar b me digits bachi hai toh usko add karo
            if (n >= 0) {
                carry += b[n] - '0';
                n--;
            }
            // current digit result me add karo
            ans += ((carry % 2) + '0');
            // naye carry ko update karo
            carry = carry / 2;
        }
        // result ko reverse karo kyunki humne end se shuru kiya tha
        reverse(ans.begin(), ans.end());
        return ans; 
    }
};
