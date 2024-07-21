
// LINK : https://leetcode.com/problems/intersection-of-two-arrays/description/


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>st;
        for(int i =0;i<nums1.size();i++){
            for(int j =0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]) st.insert(nums1[i]);
            }
        }
        vector<int>ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int>nums1 = {1,2,2,1}, nums2 = {2,2};
    vector<int>ans = s.intersection(nums1,nums2);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;

}