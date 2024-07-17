
// Author : Shivam Kumar
// Date : 25/11/2022

// Problem Link : https://leetcode.com/problems/maximal-rectangle/

#include <bits/stdc++.h>
using namespace std;
// Optimized Solution :  Using Monotonic Stack
// Complexity : O(M * N);

class Solution
{
public:
    int ar(vector<int> &height)
    {
        stack<int> st;
        int n = height.size();
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || height[st.top()] > height[i]))
            {
                int h = height[st.top()];
                st.pop();
                int w;
                w = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, h * w);
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            int area = ar(height);
            ans = max(ans, area);
        }
        return ans;
    }
};

int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '0'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    Solution s;
    cout << s.maximalRectangle(matrix);
    return 0;
}

// Brute Force : Funtion()
// Time Complexity : O(n^3)
// Space Complexity : O(1)

// class Solution {
// public:
//     int findArea(vector<vector<char>>& matrix, int i, int j, int n, int m) {
//     if (matrix[i][j] == '0') return 0;

//     int maxArea = 0;
//     int height = 0;

//     for (int k = i; k < n; k++) {
//         if (matrix[k][j] == '1') {
//             height++;
//         } else {
//             break;
//         }
//     }
//     // cout<<height<<" ";

//     int width = 0;
//     for (int k = j; k < m; k++) {
//         if (matrix[i][k] == '1') {
//             width++;
//             int tm = 0;
//             for (int l = i; l < n; l++) {
//                 if (matrix[l][k] == '1') {
//                     tm++;
//                 } else {
//                     break;
//                 }
//             }
//             height = min(tm,height);
//             maxArea = max(maxArea, width * height);
//         }
//         else {
//             break;
//         }
//     }
//     cout<<width<<" and "<<height<<endl;

//     return maxArea;
// }

//     int maximalRectangle(vector<vector<char>>& matrix) {
//         int maxarea = 0;
//         int n = matrix.size();
//         int m = matrix[0].size();

//         for(int i =0;i<n;i++){
//             for(int j =0;j<m;j++){
//                 int area = findArea(matrix,i,j,n,m);
//                 maxarea = max(maxarea,area);
//             }
//         }
//         return maxarea;
//     }
// };