
// LINK :  https://leetcode.com/problems/sum-of-left-leaves/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int Sum(TreeNode* root,string s){
        if(!root) return 0;
        if(!root->left && !root->right){
            if(s=="left") return root->val;
        }
         int lst = Sum(root->left,"left");
         int rst = Sum(root->right,"right");

         return lst + rst;
    }
    int sumOfLeftLeaves(TreeNode* root) {
       return Sum(root,"");
    }
};