
// Problem Link : https://leetcode.com/problems/combination-sum-ii/

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    void solve(vector<int> &candidates, int target, int i, vector<int> &res)
    {
        if (target == 0)
        {
            ans.push_back(res);
            return;
        }
        if (i >= candidates.size() || target < 0)
            return;

        for (int j = i; j < candidates.size(); j++)
        {
            // skip duplicates numbers, kyoki vector sorted hai
            if (j > i && candidates[j] == candidates[j - 1])
                continue;
            res.push_back(candidates[j]);
            solve(candidates, target - candidates[j], j + 1, res);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> res;
        solve(candidates, target, 0, res);
        return ans;
    }
};
