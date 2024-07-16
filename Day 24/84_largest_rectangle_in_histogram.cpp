

// LINK : https://leetcode.com/problems/largest-rectangle-in-histogram/description/

// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> NSL(vector<int>&h,int n){
        vector<int>nsl(n,-1);
        stack<int>st;
        st.push(0);
        for(int i =1;i<n;i++){
            while(!st.empty() && h[i]<=h[st.top()]) st.pop();

            nsl[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return nsl;
    }
    vector<int> NSR(vector<int>&h,int n){
        vector<int>nsr(n,n);
        stack<int>st;
        st.push(n-1);
        for(int i =n-2;i>=0;i--){
            while(!st.empty() && h[i]<=h[st.top()]) st.pop();

            nsr[i] = st.empty()?n:st.top();
            st.push(i);
        }
        return nsr;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsl = NSL(heights,heights.size());
        vector<int> nsr = NSR(heights,heights.size());
        int ans = 0;
        for(int i =0;i<heights.size();i++){
            int w = nsr[i] - nsl[i] - 1;
            int h = heights[i];
            int area = h*w;
            if(area>ans) ans = area;
        }

        return ans;
    }
};
int main(){
    Solution s;
    vector<int>h = {2,1,5,6,2,3};
    cout<<s.largestRectangleArea(h);
    return 0;
}