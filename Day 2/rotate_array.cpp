// Author : Shivam Kumar
// Example 1:
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

// Example 2:
// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]

#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = height.size();
        int left = 0, right = s - 1;
        int ans = 0;
        while (left < right) {
            int l = height[left];
            int r = height[right];
            int min_h = min(l, r);
            int len = right - left; // Finding length between two pointers
            ans = max(ans, min_h * len); // Calculate total height
            
            // Update left or right pointer according to needs
            if (l < r)
                left++;
            else
                right--;
        }
        return ans;
    }
};

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution solution;

    int result = solution.maxArea(height);
    cout << "Maximum area: " << result << endl;

    return 0;
}
