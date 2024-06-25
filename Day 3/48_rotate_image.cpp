// Author : Shivam kumar

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

#include <iostream>
#include <vector>
#include <algorithm>  // For std::swap

using namespace std;

class Solution {
public:
    // Function to reverse a 1D vector
    void reverse(vector<int>& v) {
        int m = v.size();
        int f = 0, l = m - 1;
        while (f < l) {
            swap(v[f], v[l]);
            f++;
            l--;
        }
    }

    // Function to transpose a 2D vector (matrix)
    void transpose(vector<vector<int>>& arr) {
        int m = arr.size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                swap(arr[i][j], arr[j][i]);
            }
        }
    }

    // Function to rotate a 2D vector (matrix) by 90 degrees clockwise
    void rotate(vector<vector<int>>& arr) {
        int row = arr.size();
        transpose(arr);
        for (int i = 0; i < row; i++) {
            reverse(arr[i]);
        }
    }
};

int main() {
    Solution solution;

    // Example 2D vector (matrix) to be rotated
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Display the original matrix
    cout << "Original Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Rotate the matrix
    solution.rotate(matrix);

    // Display the rotated matrix
    cout << "\nRotated Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
