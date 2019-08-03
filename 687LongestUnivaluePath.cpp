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
    int longestUnivaluePath(TreeNode* root) {
        int lup = 0;
        LUP(root, lup);
        return lup;
    }
    
    int LUP(TreeNode* root, int& lup) {
        if (!root)
            return 0;
        
        int l = root->left ? LUP(root->left, lup) : 0;
        int r = root->right ? LUP(root->right, lup) : 0;
        int root2l = root->left && root->left->val == root->val ? l+1 : 0;
        int root2r = root->right && root->right->val == root->val ? r+1 : 0;
        lup = max(lup, root2l+root2r);
        return max(root2l, root2r);
    }
};

// 这是一道easy。。。我知道是dfs，但是写不太出来，看了高赞以后，理解了自己写出来的。还是自己太菜了，继续加油！下面是高赞答案的解释
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int lup = 0;
        if (root) dfs(root, lup);
        return lup;
    }

private:
    int dfs(TreeNode* node, int& lup) {
        int l = node->left ? dfs(node->left, lup) : 0;
        int r = node->right ? dfs(node->right, lup) : 0;
        int resl = node->left && node->left->val == node->val ? l + 1 : 0;
        int resr = node->right && node->right->val == node->val ? r + 1 : 0;
        lup = max(lup, resl + resr);
        return max(resl, resr);
    }
};
/**
l is the length of single direction Longest-Univalue-Path start from left-child,
r is the length of single direction Longest-Univalue-Path start from right-child,
resl is the length of single direction Longest-Univalue-Path start from parent go left,
resr is the length of single direction Longest-Univalue-Path start from parent go right.
int dfs(node) returns the Longest-Univalue-Path-Start-At that node, and update the result of Longest-Univalue-Path-Across that node through side effect.
It is really hard to name those variables to reflect these concept.
*/