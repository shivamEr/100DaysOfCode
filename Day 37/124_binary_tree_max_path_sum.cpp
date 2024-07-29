

// LINK :  https://leetcode.com/problems/binary-tree-maximum-path-sum/
// LEVEL : HARD

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
int sumPath(TreeNode* root,int &mx){
    if(!root) return 0;
    
    // left and right dono side max path bta de
    int lst = max(0,sumPath(root->left,mx));
    int rst = max(0,sumPath(root->right,mx));

    // update mx, agar jayada path mile to
    mx = max(mx,(lst+rst+root->val));
    // return current max path
    return max(lst,rst)+root->val;
}


    int maxPathSum(TreeNode* root) {
    // ye hamesa max ko store krega
       int mx = INT_MIN;
       sumPath(root,mx);
       return mx;
    }
};