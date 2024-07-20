
// LINK : https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/?envType=daily-question&envId=2024-07-20

// Input: rowSum = [5,7,10], colSum = [8,6,8]
// Output: [[0,5,0],
//          [6,1,0],
//          [2,0,8]]
 

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        int n = rowSum.size();
        int m = colSum.size();
        // For Storing Ans
        vector<vector<int>> matrix(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= matrix[i][j];
                colSum[j] -= matrix[i][j];
            }
        }
        return matrix;
    }
};

int main()
{
    Solution s;
    vector<int> rowSum = {5, 7, 10};
    vector<int> colSum = {8, 6, 8};
    vector<vector<int>> ans = s.restoreMatrix(rowSum, colSum);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}