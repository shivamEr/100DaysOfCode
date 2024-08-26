
// Problem Link : https://leetcode.com/problems/n-ary-tree-postorder-traversal/


class Solution {
public:
    void solve(Node* root,vector<int>&ans){
        if(root->children.size()<=0){
            ans.push_back(root->val);
            return;
        };
        for(int i =0;i<root->children.size();i++){
            solve(root->children[i],ans);
        }
        ans.push_back(root->val);
        return;
    }
    vector<int> postorder(Node* root) {
        if(!root) return {};
        vector<int>ans;
        // stack<Node*>st;
        solve(root,ans);
        return ans;
    }
};

