
// Problem Link : https://leetcode.com/problems/spiral-matrix-iii/description/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        vector<vector<int>> ans;
        vector<vector<int>> direction = {
            {0, 1},  // For East Move
            {1, 0},  // For South Move
            {0, -1}, // For West
            {-1, 0}  // For North
        };

        int dir = 0;   // index 0 denote East direction
        int steps = 0; // ye kitna steps move karna btayega

        ans.push_back({rStart, cStart}); // Start Position push karna prega

        while (ans.size() < rows * cols)
        {
            // direction EAST or WEST ho tab
            if (dir == 0 || dir == 2)
            {
                steps++;
            }

            // Move steps
            for (int cnt = 0; cnt < steps; cnt++)
            {
                rStart += direction[dir][0];
                cStart += direction[dir][1];

                // check karega out of bound hai kya
                if (rStart >= 0 && cStart >= 0 && rStart < rows && cStart < cols)
                {
                    ans.push_back({rStart, cStart});
                }
            }
            // change direction circularly
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> ans = s.spiralMatrixIII(5, 6, 1,4);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}