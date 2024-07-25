

// LINK  : https://leetcode.com/problems/sort-an-array/description/

// Without using any built in function
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums, int left, int right, int mid)
    {
        // sort karke store karenge
        vector<int> ans;
        int l = left;    // start location left part ka
        int r = mid + 1; // start location right part ka

        // jab tak left part or right part koe bhi cross na kr le
        while (l <= mid && r <= right)
        {
            if (nums[l] <= nums[r])
            {
                ans.push_back(nums[l]);
                l++;
            }
            else
            {
                ans.push_back(nums[r]);
                r++;
            }
        }

        // agar left part ka size jayada hoga to run hoga
        while (l <= mid)
        {
            ans.push_back(nums[l]);
            l++;
        }
        // same agar right part ka size jayada ho
        while (r <= right)
        {
            ans.push_back(nums[r]);
            r++;
        }
        // Ab answer ko correct location pe assing bhi to krna hai
        for (int i = left; i <= right; i++)
        {
            nums[i] = ans[i - left];
        }
    }
    void mergeSort(vector<int> &nums, int left, int right)
    {
        // base case, jab element single ho jayega
        if (left >= right)
            return;
        // mid nikal lete hai, devide karna hai na
        int mid = left + (right - left) / 2;
        // left part ko pass kiya
        mergeSort(nums, left, mid);
        // right part ko pass kiya
        mergeSort(nums, mid + 1, right);

        // Ab merge bhi to karna hai, sorted order me
        merge(nums, left, right, mid);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, 2, 3, 1};
    s.sortArray(nums);
    return 0;
}