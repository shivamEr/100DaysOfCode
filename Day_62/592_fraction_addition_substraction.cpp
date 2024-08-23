

// Problem Link : https://leetcode.com/problems/fraction-addition-and-subtraction/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionAddition(string exp) {
        int nume = 0, deno = 1; 
        int i = 0;
        int n = exp.size(); 

        while (i < n) {
            int sign = 1;
            // Yadi '+' ya '-' sign aata hai to sign ko samayojit karen
            if (exp[i] == '+' || exp[i] == '-') {
                if (exp[i] == '-') sign = -1;
                i++;
            }

            int num = 0;
            // Yaha par number ko obtain karte hain
            while (i < n && isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            num *= sign;
            i++;
            int den = 0;
            // Yaha par denominator  ko obtain karte hain
            while (i < n && isdigit(exp[i])) {
                den = den * 10 + (exp[i] - '0');
                i++;
            }
            // Naye numerator aur denominator ka hisaab lagate hain
            nume = nume * den + num * deno;
            deno *= den;

            // GCD se numerator aur denominator ko simplify karte hain
            int gcdVal = gcd(abs(nume), deno);
            nume /= gcdVal;
            deno /= gcdVal;
        }
        return to_string(nume) + '/' + to_string(deno); 
    }
};

int main(){
    Solution obj;
    string exp = "1/2+1/2+1/3";
    cout << obj.fractionAddition(exp) << endl;
    return 0;
}