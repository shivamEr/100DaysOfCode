
// Problem Link : https://leetcode.com/problems/combination-sum/

class Solution
{
public:
    vector<vector<int>> ans;
    void solve(vector<int> &candi, int target, int i, vector<int> res)
    {
        if (target == 0)
        {
            ans.push_back(res);
            return;
        }
        if (target < 0 || i >= candi.size())
            return;

        for (int j = i; j < candi.size(); j++)
        {
            res.push_back(candi[j]);
            solve(candi, target - candi[j], j, res);
            res.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> res;
        solve(candidates, target, 0, res);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> candidates = {2, 3, 5};
    int target = 8;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}