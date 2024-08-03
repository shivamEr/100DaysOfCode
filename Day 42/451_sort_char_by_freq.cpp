
// Problem Link : https://leetcode.com/problems/sort-characters-by-frequency/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // ye frequency count krega
        unordered_map<char,int>um;
        for(auto it:s){
            um[it]++;
        }
        // max heap to find most freq on top
        priority_queue<pair<int,char>>pq;
        for(auto it:um){
            pq.push({it.second,it.first});
        }
        // final ans store hoga
        string ans;
        while(!pq.empty()){
            // ye most frequent character store krega
            char ch = pq.top().second;
            // ye frequency store krega
            int fre = pq.top().first;
            pq.pop();
            // freq utna ch add hoga
            while(fre--){
                ans+=ch;
            }

        }
        return ans;
    }
};

int main(){
    Solution obj;
    string s = "tree";
    cout<<obj.frequencySort(s)<<endl;
    return 0;
}