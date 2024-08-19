
// Problem Link : https://leetcode.com/problems/group-anagrams/


#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < n; i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat"};
    vector<vector<string>> result = solution.groupAnagrams(strs);
    for (auto it : result)
    {
        for (auto str : it)
        {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}