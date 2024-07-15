
// LINK : https://leetcode.com/problems/asteroid-collision/description/

// Input: asteroids = [5,10,-5]
// Output: [5,10]
// Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &astr)
    {
        int n = astr.size();
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push(astr[i]);
            }
            else
            {
                bool flag = false;
                while (!st.empty() && st.top() > 0 && astr[i] < 0)
                {
                    if (abs(st.top()) > abs(astr[i]))
                    {
                        flag = true;
                        break;
                    }
                    else if (abs(astr[i]) == abs(st.top()))
                    {
                        st.pop();
                        flag = true;
                        break;
                    }
                    else if (abs(st.top()) < abs(astr[i]))
                    {
                        st.pop();
                    }
                }
                if (!flag)
                {
                    st.push(astr[i]);
                }
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> astr = {5, 10, -5};
    vector<int> ans = s.asteroidCollision(astr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}