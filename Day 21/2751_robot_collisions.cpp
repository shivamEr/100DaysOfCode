
// LINK : https://leetcode.com/problems/robot-collisions/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int>pos;
        for(int i =0;i<positions.size();i++) pos.push_back(i);

        auto compare = [&](int i, int j){
            return positions[i]<=positions[j];
        };
        sort(pos.begin(), pos.end(), compare);

        stack<int>st;
        for(auto ind : pos){
            if(directions[ind]=='R') st.push(ind);
            else{
                while(!st.empty() && healths[ind]>0){
                    if(healths[ind]>healths[st.top()]){
                        healths[ind]--;
                        healths[st.top()]=0;
                        st.pop();
                    }
                    else if(healths[ind]<healths[st.top()]){
                        healths[ind]=0;
                        healths[st.top()]--;
                    }
                    else{
                        healths[st.top()]=0;
                        healths[ind]=0;
                        st.pop();
                    }
                }
            }
        }
        vector<int>ans;
        for(auto i:healths) {
            if(i>0) ans.push_back(i);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int>pos = {1, 2, 3, 4, 5};
    vector<int>healths = {5, 3, 2, 1,4};
    string directions = "RRLLR";
    vector<int>ans = s.survivedRobotsHealths(pos, healths, directions);
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;

}