

// LINK : https://leetcode.com/problems/binary-tree-paths/

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
    void solve(TreeNode *root, string s,vector<string>&ans){
        if(!root) return;
        if(!root->left && !root->right){
            s = s+to_string(root->val);
            ans.push_back(s);
            return ;
        }
        s += to_string(root->val);
        s += "->";
        solve(root->left,s,ans);
        solve(root->right,s,ans);

        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        // if(!root) return 0;
        vector<string>ans;
        string s;
        solve(root,s,ans);
        return ans;
    }
};