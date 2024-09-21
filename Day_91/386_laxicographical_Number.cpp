
// Problem Link : https://leetcode.com/problems/lexicographical-numbers/

class Solution {
public:

    void solve(int n, int curr, vector<int>&ans){
        // base case, jab curr hi > ho jaye n se
        if(curr>n) return;
        // pushed in answer
        ans.push_back(curr);

        // har bar 0-9 append karna hai
        for(int append =0;append<=9;append++){
            // append 0-9 and passed as curr
            int num = (curr*10)+append;
            if(num>n) return;
            solve(n,num,ans);
        }
        return;

    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        // iteration 1 - 9 kyoki lexicographical me generate karna hai
        for(int i =1;i<=9;i++){
            solve(n,i,ans);
        }
        return ans;
    }
};

// Optimize Brute-Force


// class Solution {
// public:
//     vector<int> lexicalOrder(int n) {
//         vector<string>ans;
//         for(int i =1;i<=n;i++){
//             ans.push_back(to_string(i));
//         }
//         sort(ans.begin(),ans.end());
//         vector<int>finalAns;
//         for(auto it:ans){
//             finalAns.push_back(stoi(it));
//         }

//         return finalAns;

//     }
// };