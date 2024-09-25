

// Problem Link : https://leetcode.com/problems/find-missing-observations/description/

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for(auto it: rolls) sum+=it;
        
        int totalSum = mean * (m+n);
        int remSum = totalSum - sum;
        if(remSum > 6*n || remSum < n) return {};

        int num = remSum/n;
        vector<int>ans(n,num);
        int rem = remSum%n;

        for(int i =0 ;i<n;i=(i+1)%n){
            if(rem==0) break;
            ans[i]++;
            rem--;
        }


        return ans;
    }
};