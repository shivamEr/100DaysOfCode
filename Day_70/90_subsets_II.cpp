

// Problem Link : https://leetcode.com/problems/subsets-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //  set jo unique subset store krega
    set<vector<int>> ans;

    void solve(vector<int> nums, vector<int> sub, int ind)
    {
        // base case
        if (ind == nums.size())
        {
            ans.insert(sub);
            return;
        }
        // take not take approach
        solve(nums, sub, ind + 1);
        sub.push_back(nums[ind]);
        solve(nums, sub, ind + 1);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> sub;
        // sort nums for finding
        sort(nums.begin(), nums.end());
        solve(nums, sub, 0);
        vector<vector<int>> finalAns(ans.begin(), ans.end());
        return finalAns;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = s.subsetsWithDup(nums);
    for (auto it : ans)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
    return 0;
}