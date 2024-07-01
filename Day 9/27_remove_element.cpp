// Shivam Kumar

// 27. Remove Element from Array and return size after removed
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int ind = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[ind] = nums[i];
                ind++;
            }
        }
        // nums.resize(ind);
        return ind;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    cout << s.removeElement(nums, val) << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}