
// LINK : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode* root,TreeNode* node, vector<TreeNode*>&path){
        // base case, agar mil gya to push and return true
        if(root==node){
            path.push_back(root);
            return true;
        }
        if(!root) return false;
    //  man ke jalte hai ye path ka hissa hoga
        path.push_back(root);
    // check left side me path hai kya
        if(findPath(root->left,node,path)) return true;
    // check right side me path hai kya
        if(findPath(root->right,node,path)) return true;
    //  agar path nhi mila to pop() to karna parega
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root; // Agar root hai to kya return kar
        vector<TreeNode*>path1,path2; // dono ka path find karenge
        findPath(root,p,path1); // p ka path bta de
        findPath(root,q,path2); // q ka path bta de
    //  dono ke size min se left me pahala kon match kar rha hai
        for(int i= min(path1.size(),path2.size())-1;i>=0;i--){
            if(path1[i]==path2[i]) return path1[i];
        }
        return NULL; // koe kam nhi hai, yuhi return kar diya
    }
};






// SPACE OPTIMIZE CODE

// class Solution {
// public:
//     TreeNode* solve(TreeNode *root, TreeNode* p,TreeNode* q){
//         if(!root) return NULL;
//         if(root==p || root == q){
//             return root;
//         }
//         TreeNode* lst = solve(root->left,p,q);
//         TreeNode* rst = solve(root->right,p,q);

//         if(lst && rst){
//             return root;
//         }
//         else if(lst) return lst;
//         else if(rst) return rst;
//         return NULL;
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         return solve(root,p,q);
//     }
// }; 