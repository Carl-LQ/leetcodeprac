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
    
    TreeNode* pruneTree(TreeNode* root) {
        if (!root)
            return NULL;
        
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->val == 0 && !root->left && !root->right) {
            return NULL;
        } else {
            return root;
        }
    }
};

// 我也不知道我怎么想出来的，就比较典型的一道递归题，然后就写出来了- -