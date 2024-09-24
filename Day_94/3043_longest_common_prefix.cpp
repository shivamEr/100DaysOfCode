
// Problem Link : https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        unordered_map<string,int>hash;

        int tm = 0;
        for(int i = 0; i<n1;i++){
           while(arr1[i]){
              string s =to_string(arr1[i]);
              hash[s]++;
              arr1[i] /= 10;
           }
        }

        // finding longest prefix
        int prefixlen = 0;
        for(int i =0;i<n2;i++){
            bool flag = true;
           while(arr2[i] && flag){
             string s = to_string(arr2[i]);

             if(hash.count(s)){
                int size = s.size();
                prefixlen = max(prefixlen, size);
                flag = false;
             }
             arr2[i] /= 10;
           }
        }
        return prefixlen;
    }
};