
// Problem Link : https://leetcode.com/problems/subsets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Global variable jo final result store krega
    vector<vector<int>> ans;

    void solve(vector<int> nums, vector<int> sub, int ind)
    {
        // base case
        if (ind == nums.size())
        {
            ans.push_back(sub);
            return;
        }
        // take not take approach
        solve(nums, sub, ind + 1);
        sub.push_back(nums[ind]);
        solve(nums, sub, ind + 1);
        return;
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> sub;
        solve(nums, sub, 0);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = s.subsets(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
