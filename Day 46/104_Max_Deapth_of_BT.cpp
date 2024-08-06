
// Problem Link : https://leetcode.com/problems/maximum-depth-of-binary-tree/

// Input: root = [3,9,20,null,null,15,7]
// Output: 3
// Example 2:

// Input: root = [1,null,2]
// Output: 2

class Solution {
public:
    int solve(TreeNode* root){
        if(!root) return 0;

        int lst = solve(root->left);
        int rst = solve(root->right);

        return max(lst,rst)+1;
    }
    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};