
// Problem Link : https://leetcode.com/problems/convert-1d-array-into-2d-array/description

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        int s = original.size();
        if (s != (m * n))
            return {};
        vector<vector<int>> ans(m, vector<int>(n));
        int ind = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[i][j] = original[ind++];
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> original = {1, 2, 3};
    int m = 1, n = 3;
    vector<vector<int>> ans = s.construct2DArray(original, m, n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}