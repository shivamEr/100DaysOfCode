
// Problem Link :  https://leetcode.com/problems/binary-tree-right-side-view/


class Solution {
public:
    void solve(TreeNode* root,vector<int>&ans){
        if(!root) return;

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            for(int i =1;i<=s;i++){
                TreeNode* n = q.front();
                q.pop();
                if(i==1) ans.push_back(n->val);
                if(n->right) q.push(n->right);
                if(n->left) q.push(n->left);

            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};