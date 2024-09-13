
// Problem Link : https://leetcode.com/problems/xor-queries-of-a-subarray/description/


// My Brute Force Approach : 

// class Solution {
// public:
//     int findXor(int ind1,int ind2, vector<int>&arr){
//         int n = arr[ind1++];
//         while(ind1<=ind2){
//             n = n^ arr[ind1++];
//         }
//         return n;
//     }
//     vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
//         vector<int>ans;
//         // iterate over queries
//         int s = queries.size();
//         for(int i =0;i<s;i++){
//             int ind1= queries[i][0];
//             int ind2= queries[i][1];
//             int num = findXor(ind1,ind2,arr);
//             ans.push_back(num);
//         }
//         return ans;
//     }
// };


// Optimize Approach :

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        int n = arr.size();
        vector<int>ans;
        // finding prefix with xor
        for(int i =1;i<n;i++){
            arr[i] ^= arr[i-1];
        }
        // iterate over queries
        int s = q.size();
        for(int i =0;i<s;i++){
            int ind1= q[i][0];
            int ind2= q[i][1];
            
            if(ind1>0) ans.push_back(arr[ind1-1] ^ arr[ind2]);
            else ans.push_back(arr[ind2]);
        }
        return ans;
    }
};