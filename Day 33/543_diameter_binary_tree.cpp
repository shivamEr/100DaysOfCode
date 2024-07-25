

// LINK : https://leetcode.com/problems/diameter-of-binary-tree/description/

// Easy hai yar bas each node pe check karna hai maximum diameter kyki left me or right me bhi ho skata hai
class Solution {
public:
    int height(TreeNode* root){
        // Agar Null hai to return kar de 
        if(!root) return 0; 
        // find kar lete hai left kar height 
        int l = 1 + height(root->left);
        // find kar lete hai right kar height
        int r = 1 + height(root->right);
        // return kar de maximum height
        return max(r,l);
    }
    int ans =INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        // find left height of current node
        int lst = height(root->left);
        int rst = height(root->right);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        ans = max(ans,lst+rst);
        return ans;
    }
};

