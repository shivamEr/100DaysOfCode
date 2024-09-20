
// Problem Link  : https://leetcode.com/problems/sum-of-subarray-minimums/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        
        vector<int>pse(n);
        vector<int>nse(n);
        pse = findNSE(arr,n);
        nse = findPSE(arr,n);

        long long ans = 0;
        for(int i = 0; i<n; i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            ans = (ans + (right * left * arr[i])%mod)%mod;
        }
        return ans;
    }

    vector<int>findNSE(vector<int>arr,int n){
        vector<int>nse(n);
        stack<int>st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])
            st.pop();

            nse[i] = st.empty()? n : st.top();
            st.push(i);
        }
        return nse;
    }


    vector<int>findPSE(vector<int>arr,int n){
        vector<int>pse(n,0);
        stack<int>st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i])
            st.pop();

            pse[i] = st.empty()? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
};