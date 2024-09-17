
// Problem Link : https://leetcode.com/problems/uncommon-words-from-two-sentences/description

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // hash map jo string ka frequency store krega
        map<string,int>mp;

        string word;
        // tokenize first sentances to word
        for (char c : s1) {
            if (c == ' ') {            
                mp[word]++;
                word = "";
            }
            else word += c;
        }
        if (!word.empty()) mp[word]++;

        word = "";
        // tokenize second sentances to words
        for (char c : s2) {
            if (c == ' ') {            
                mp[word]++;
                word = "";
            }
            else word += c;
        }
        if (!word.empty()) mp[word]++;
        // finding answer based on frequency
        vector<string>ans;
        for(auto it:mp){
            pair<string,int>p = it;
            if(p.second==1) ans.push_back(p.first);
        }

        return ans;
    }
};