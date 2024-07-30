
// LINK : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

class Solution {
public:
    TreeNode* insertBST(vector<int>&nums,int s,int e){
        // jab start bda ho jaye end se eska mtlb array empty ho gya
        if(s>e){
            return NULL;
        }
        // mid nikal lete hai
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        // left me leftTree bna de
        root->left = insertBST(nums,s,mid-1);
        // right me rightTree bna de
        root->right = insertBST(nums,mid+1,e);
       
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // finding size
        int n = nums.size();
        // create BST 
        TreeNode* root = insertBST(nums,0,n-1);
        return root;
    }
};

