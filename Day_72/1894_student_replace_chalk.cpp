
// Problem Link : https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
       int n = chalk.size();
       if(n==1) return 0;
       long long int sum =0;
       // calculated sum of chalk
       for(auto it:chalk) sum+=it;;

       // finding remaining sum
        k=k%sum;
        
       // iterate and check
       for(int i =0;i<n;i++){
        if(chalk[i]>k) return i;
        k = k-chalk[i];
       }
       return 0;
    }
};
int main(){
    Solution s;
    vector<int> v = {5,1,5};
    int k = 22;
    cout<<s.chalkReplacer(v,k)<<endl;
    return 0;
} 
