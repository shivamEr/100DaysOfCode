

// LINK : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        int profit = 0; // final profit will be stored
        int mini = INT_MAX;
        for(int i =0;i<n-1;i++){
            if(prices[i]<prices[i+1] && prices[i]<mini){
                mini = prices[i];
            }
            if(mini<prices[i+1]){
                profit = max(profit,prices[i+1]-mini);
            }
        }
        return profit;

    }
};

int main(){
    Solution s;
    vector<int> v = {7,1,5,3,6,4};
    cout<<s.maxProfit(v);
    return 0;
}

// CLEAR AND CONCISE SOLUTION :

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//        int buyPrice = prices[0];
//         int profit = 0;

//         for (int i = 1; i < prices.size(); i++) {
//             if (buyPrice > prices[i]) {
//                 buyPrice = prices[i];
//             }

//             profit = max(profit, prices[i] - buyPrice);
//         }

//         return profit;        
    
//     }
// };

