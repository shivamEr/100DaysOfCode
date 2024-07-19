
// LINK : https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> mat)
    {
        int ind = 0;
        int num = mat[0];
        for (int i = 1; i < mat.size(); i++)
        {
            if (num > mat[i])
            {
                num = mat[i];
                ind = i;
            }
        }
        return ind;
    }
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int minInd = findMin(matrix[i]);
            bool flag = false;
            for (int k = 0; k < n; k++)
            {
                if (matrix[k][minInd] <= matrix[i][minInd])
                    flag = true;
                else
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.push_back(matrix[i][minInd]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    vector<int> ans = s.luckyNumbers(matrix);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}