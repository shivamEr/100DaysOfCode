

// Problem Link : https://leetcode.com/problems/spiral-matrix-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n));
        int top = 0, left = 0, buttom = n - 1, right = n - 1;
        int num = 0;
        while (left <= right && top <= buttom)
        {
            // ye top row ke liye
            for (int i = left; i <= right; i++)
            {
                ans[top][i] = ++num;
            }
            top++;
            // ye right column ke liye
            for (int i = top; i <= buttom; i++)
            {
                ans[i][right] = ++num;
            }
            right--;

            // buttom row ke liye
            for (int i = right; i >= left; i--)
            {
                ans[buttom][i] = ++num;
            }
            buttom--;

            // left column ke liye
            for (int i = buttom; i >= top; i--)
            {
                ans[i][left] = ++num;
            }
            left++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n = 3;
    vector<vector<int>> ans = s.generateMatrix(n);
    cout << "Following is the matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}