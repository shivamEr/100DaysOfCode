// Author : Shivam Kumar
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1

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
            int len = right - left;
            ans = max(ans, min_h * len);

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
