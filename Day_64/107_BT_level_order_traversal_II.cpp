

// Problem Link : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        vector<vector<int>>ans;

        q.push(root);
        while(q.size()){
            int s = q.size();
            vector<int>temp(s);
            for(int i =0;i<s;i++){
                TreeNode* f = q.front();
                 q.pop();
                temp[i] = f->val;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

