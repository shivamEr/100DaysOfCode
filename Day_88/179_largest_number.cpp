
// Problem Link : https://leetcode.com/problems/largest-number/

class Solution {
public:
    string largestNumber(vector<int>& arr) {
        // sorting, compare function (true/false)
        sort(arr.begin(), arr.end(), [](int num1, int num2){
            string s1 = to_string(num1);
            string s2 = to_string(num2);

            if((s1+s2) > (s2+s1)) return true;
            return false;
        });

        // Agar first index pe zero ho to return "0"
        if(arr[0]==0) return "0";
        
        // Stored answer in String form
        string ans;
        for(auto it: arr){
            ans+=to_string(it);
        }
        return ans;
    }
};