
// LINK : https://leetcode.com/problems/k-closest-points-to-origin/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        // pq high dist wala point ko top rakhega
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < points.size(); i++)
        {
            int dist = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            // pq me push with dist and index
            pq.push({dist, i});
            // k se jayada size hoga to pop kar de
            if (pq.size() > k)
                pq.pop();
        }
        // for storing answer
        vector<vector<int>> ans;
        while (!pq.empty())
        {
            // finding index from the pair
            int ind = pq.top().second;
            ans.push_back(points[ind]);
            pq.pop();
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {-2, 0}, {0, 0},
     {2,2}, {1, -1}, {-2, -2}};
    int k = 3;
    vector<vector<int>> ans = s.kClosest(points, k);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}