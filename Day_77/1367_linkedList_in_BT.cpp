

// Problem Link : https://leetcode.com/problems/linked-list-in-binary-tree/


class Solution {
public:
    bool solve(ListNode* head, TreeNode* root){
        if(head == NULL) return true;
        if(root == NULL) return false;
    //  Check it
        if (head->val != root->val) return false;

        return solve(head->next, root->left) || solve(head->next, root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == NULL) return false;
        // Check Krega using DFS
        return solve(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};