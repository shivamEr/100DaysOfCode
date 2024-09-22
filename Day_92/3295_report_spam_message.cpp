
// Problem Link : https://leetcode.com/problems/report-spam-message/

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        map<string,int>mp;
        for(auto it: bannedWords){
            mp[it]++;
        }
        bool ans = false;
        int cnt = 0;

        for(auto it: message){
            if(mp.find(it)!=mp.end()) cnt++;
            if(cnt >=2) return true;
        }
        return ans;
    }
};


// USED SET FOR OPTIMIZED CODE, BECAUSE SET AVERAGE TAKES O(1) TO FIND

// class Solution {
// public:
//     bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
//         unordered_set<string> b(begin(bannedWords), end(bannedWords));
//         int cnt = 0;
//         for(auto& m : message) {
//             if(b.count(m)) {
//                 if(++cnt >= 2) break;
//             }
//         }
//         return cnt >= 2;
//     }
// };