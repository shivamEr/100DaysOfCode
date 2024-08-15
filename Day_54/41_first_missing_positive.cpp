
// Problem Link : https://leetcode.com/problems/first-missing-positive/description/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // sorting for finding !st +ve
        sort(nums.begin(),nums.end());
        // check, is nums contains +ve num
        if(nums.back()<=0) return 1;
        int key = 1;
        for(int i =0;i<nums.size();i++){
        // skip negative nums and duplicate
           if(nums[i]<=0 || nums[i]==key-1) continue;
           else if(nums[i]==key) key++;
           else return key;
        }
        return nums.back()+1;
    }
};

int main(){
    Solution s;
    vector<int> v = {1,2,0};
    cout<<s.firstMissingPositive(v)<<endl;
    return 0;
}


