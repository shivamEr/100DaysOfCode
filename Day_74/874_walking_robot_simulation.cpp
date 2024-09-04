

// Problem Link : https://leetcode.com/problems/walking-robot-simulation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        // N , E, S, W
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // ye abstackled ko store krega
        unordered_set<string> obs;

        for (auto &it : obstacles)
        {
            // assign obstackle as key
            obs.insert(to_string(it[0]) + ',' + to_string(it[1]));
        }

        int d = 0, x = 0, y = 0, mxDist = 0;

        for (auto it : commands)
        {
            if (it == -1)
            {
                d = (d + 1) % 4;
            }
            else if (it == -2)
            {
                d = (d + 3) % 4;
            }

            else
            {
                while (it--)
                {
                    int tempX = x + dir[d][0];
                    int tempY = y + dir[d][1];

                    // checked for obstacles
                    if (obs.find(to_string(tempX) + ',' + to_string(tempY)) != obs.end())
                        break;

                    x = tempX;
                    y = tempY;

                    // each time calculating max dist
                    mxDist = max(mxDist, (x * x + y * y));
                }
            }
        }

        return mxDist;
    }
};