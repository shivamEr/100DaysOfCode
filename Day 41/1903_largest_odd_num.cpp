
// LINK : https://leetcode.com/problems/largest-odd-number-in-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string nums) {  
        // if(stoi(nums)%2!=0) return nums;      
        string ans;
       for(int i = nums.size()-1;i>=0;i--){
         int n = nums[i]-'0';
         if(n%2!=0){
            ans = nums.substr(0,i+1);
            break;
         }           
       }
        return ans;
    }
};

int main(){
    Solution s;
    string nums;
    cin>>nums;
    cout<<s.largestOddNumber(nums)<<endl;
    return 0;
}