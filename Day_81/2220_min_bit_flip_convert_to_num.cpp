

// Problem Link : https://leetcode.com/problems/minimum-bit-flips-to-convert-number/


class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        while(goal>0 || start>0){
            // Comparing for no matching bits 
            if((goal&1)!=(start&1)) cnt++;
            // Iteration on each bit
            start = start>>1;
            goal = goal>>1;
        }
        return cnt;
    }
};