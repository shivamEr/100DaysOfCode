
// Problem Link : https://leetcode.com/problems/lemonade-change/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(auto it:bills){
            if(it==5) five++;
            else if(it == 10){
                if(five!=0){
                    five--;
                    ten++;
                }
                else return false;
            }
            else{
                if(ten!=0){
                    ten--;
                    if(five!=0){
                        five--;
                    }
                    else return false;
                }
                else if(five-3>=0){
                    five=five-3;
                }
                else return false;
            }
        }
        return true;

    }
};

int main(){
    Solution solution;
    vector<int> bills = {5,5,10,10,20};
    cout<<solution.lemonadeChange(bills)<<endl;
    return 0;
}