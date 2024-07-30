
// LINK : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans; // final Answer will store
        if(!root) return ans; 
        queue<TreeNode*>q; // for level order travesal
        q.push(root);
        bool left_to_right = true; // helps to identify direction (l-r or r-l)
        while(!q.empty()){
            int n = q.size();
            vector<int>temp(n); // for store each level
            for(int i =0;i<n;i++){
                TreeNode* tm = q.front();
                q.pop();
                int ind = left_to_right ? i:n - i -1; // finding index with direction
                temp[ind] = tm->val; 
                // check kar left exist, agar hai to queue me push kar
                if(tm->left){
                     q.push(tm->left);
                }
                // check kar right hai, hai to push kar
                if(tm->right){
                    q.push(tm->right);
                }
            }
            // har ek level pe direction change
            left_to_right = !left_to_right; 
            ans.push_back(temp);

        }
        return ans;
    }
};