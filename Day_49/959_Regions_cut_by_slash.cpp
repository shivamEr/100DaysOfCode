

// Problem Link  : https://leetcode.com/problems/regions-cut-by-slashes/description/

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& matrix) {
        int n = matrix.size();
        queue<pair<int, int>> q;
        q.push({i, j});
        matrix[i][j] = -1; // to mark it as visited
        while (!q.empty()) {
            pair<int, int> current = q.front();
            int row = current.first;
            int col = current.second;
            q.pop();
            if (row - 1 >= 0 && matrix[row - 1][col] == 0) { // Move up
                matrix[row - 1][col] = -1;
                q.push({row - 1, col});
            }
            if (row + 1 < n && matrix[row + 1][col] == 0) { // Move down
                matrix[row + 1][col] = -1;
                q.push({row + 1, col});
            }
            if (col - 1 >= 0 && matrix[row][col - 1] == 0) { // Move left
                matrix[row][col - 1] = -1;
                q.push({row, col - 1});
            }
            if (col + 1 < n && matrix[row][col + 1] == 0) { // Move right
                matrix[row][col + 1] = -1;
                q.push({row, col + 1});
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> matrix(n * 3, vector<int>(n * 3, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int row = i * 3, col = j * 3;
                if (grid[i][j] == '/') {
                    matrix[row][col + 2] = 1;
                    matrix[row + 1][col + 1] = 1;
                    matrix[row + 2][col] = 1;
                } else if (grid[i][j] == '\\') {
                    matrix[row][col] = 1;
                    matrix[row + 1][col + 1] = 1;
                    matrix[row + 2][col + 2] = 1;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n * 3; i++) {
            for (int j = 0; j < n * 3; j++) {
                if (matrix[i][j] == 0) {
                    bfs(i, j, matrix); { cnt++; }
                }
            }
        }
        return cnt;
    }
};

int main(){
    Solution solution;
    vector<string> grid = {" /","/ ","//"};
    int regions = solution.regionsBySlashes(grid);
    return 0;
}