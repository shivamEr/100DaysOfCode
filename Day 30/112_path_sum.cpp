
// LINK : https://leetcode.com/problems/path-sum/


#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    bool hasPathSum(TreeNode* root, int target) {
        if(!root) return false;
        target = target - root->val;
        if(root->left == NULL && root->right == NULL){
            return target == 0;
        }
        bool lst = hasPathSum(root->left, target);
        bool rst =  hasPathSum(root->right, target);
       return lst || rst;

    }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(1);
    cout<<s.hasPathSum(root, 22);
    return 0;
}