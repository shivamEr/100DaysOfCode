// Author : shivam kumar
// Example 1:

// Input: n = 4, time = 5
// Output: 2
// Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
// After five seconds, the 2nd person is holding the pillow.
// Example 2:

// Input: n = 3, time = 2
// Output: 3
// Explanation: People pass the pillow in the following way: 1 -> 2 -> 3.
// After two seconds, the 3rd person is holding the pillow.
 

// Constraints:

// 2 <= n <= 1000
// 1 <= time <= 1000

#include<iostream>
using namespace std;
class Solution {
public:
    int passThePillow(int n, int time) {
       int r = time/(n-1);
       int ans =0;
       if(r%2==0){
        ans = (1+time%(n-1));
       }
       else{
        ans = (n-time%(n-1));
       }

        return ans;
    }
};

int main(){
    Solution s;
    int n = 2, time = 3;
    cout<<s.passThePillow(n,time);
    return 0;
}