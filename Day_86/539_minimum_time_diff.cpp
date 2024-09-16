

// Problem Link : https://leetcode.com/problems/minimum-time-difference/description/

class Solution {
public:
    // function jo string ko minutes me badlega
    int convertMin(string s){
        int m=0,h=0;
        for(int i =0;i<s.size();i++){
            if(i<2) h = h*10+(s[i]-'0');
            if(i>2) m = m*10+(s[i]-'0');
        }
        return (h*60)+m;
    }
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        sort(timePoints.begin(),timePoints.end());
        int upperTime = 60*24;
        int minTime = INT_MAX;
        int preMin = convertMin(timePoints[0]);
        int fInd = preMin;

        for(int i = 1; i<n;i++){
            int currMin = convertMin(timePoints[i]);
            // minimum Diff btw previous and current
            minTime = min(minTime, abs(currMin-preMin));
            preMin = currMin;
            
        }
        // checked diff btw 0 and n-1 index string
        minTime = min(minTime, abs(upperTime- convertMin(timePoints[n-1]))+fInd);
        return minTime;
    }
};