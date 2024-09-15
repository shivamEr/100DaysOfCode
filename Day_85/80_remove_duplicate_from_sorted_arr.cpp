

// Problem Link : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        int pt1 = 0, pt2 = 0;

        // iterate over the nums
        for(int i = 0;i<n;i++){
            if(nums[i]!=nums[pt1]){
                pt1 = i;
                if((i-pt1+1)<=2 && pt2!=0){
                    nums[pt2++] = nums[i];
                }
            }
            else if((i-pt1+1)<=2 && pt2!=0){
                nums[pt2++] = nums[i];
            }
            // count krega number of duplicate numbers
            if((i-pt1+1)>2) cnt++;
            // one time chalega, staring index find krne ke liye
            if((i-pt1+1)==3 && pt2==0) pt2 = i;
        }

        return n-cnt;
    }
};




//   int removeDuplicates(vector<int>& nums) {
//         if (nums.size() <= 2) return nums.size();
        
//         int index = 2;  // Start from the third element
//         for (int i = 2; i < nums.size(); i++) {
//             if (nums[i] != nums[index - 2]) {
//                 nums[index] = nums[i];
//                 index++;
//             }
//         }
        
//         return index;
//     }