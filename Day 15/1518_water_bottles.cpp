// Author : shivam kuamr

// Input: numBottles = 9, numExchange = 3
// Output: 13
// Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
// Number of water bottles you can drink: 9 + 3 + 1 = 13.

#include<iostream>
using namespace std;
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int newBottles = numBottles; // initially empty bottles is same as numBottles
        while(newBottles>=numExchange){
            int rem = newBottles % numExchange;
            newBottles /= numExchange; // getting the full waters bottel by empty bottle
            numBottles+=newBottles; // added in ans with full water
            newBottles+=rem; // updated empty bottles
        }
        return numBottles;
    }
};
int main(){
    Solution s;
    cout<<s.numWaterBottles(9,3);
    return 0;
}