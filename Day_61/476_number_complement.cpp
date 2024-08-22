
// Problem Link : https://leetcode.com/problems/number-complement/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int cnt =0;
        int n = num;
        // number of bits count krega
        while(num){
            num = num>>1;
            cnt++;
        }
        // power - 1 to ensure all bits are 1
        int ans = pow(2,cnt)-1;
        // XOR  (1 ^ 1 -> 0 , 1 ^ 0 -> 1 ) kar dega
        return n ^ ans;
    }
};

int main(){
    Solution s;
    int num = 5;
    int ans = s.findComplement(num);
    cout << ans << endl;
    return 0;
}