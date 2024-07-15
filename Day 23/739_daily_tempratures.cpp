
// LINK : https://leetcode.com/problems/daily-temperatures/description/


// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> NGR(vector<int> &temp)
    {
        int n = temp.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(n - 1);
        ans[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && temp[st.top()] <= temp[i])
            {
                st.pop();
            }
            ans[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return ans;
    }
    vector<int> dailyTemperatures(vector<int> &temp)
    {
        return NGR(temp);
    }
};

int main()
{
    Solution s;
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76};
    vector<int> ans = s.dailyTemperatures(temp);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}