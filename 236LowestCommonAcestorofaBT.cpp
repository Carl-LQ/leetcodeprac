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
    TreeNode* lowestCommonAncestor(TreeNode* cur, TreeNode* p, TreeNode* q) {
        if (cur == NULL || cur == p || cur == q) {
            return cur;
        }
        
        TreeNode* left = lowestCommonAncestor(cur->left, p, q);
        TreeNode* right = lowestCommonAncestor(cur->right, p, q);
        
        if (!left && !right) {
            return NULL;
        } else {
            return left ? (right ? cur : left) : right;
        }
    }
};