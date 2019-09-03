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
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        int sum = 0;
        getSum(root, 0, sum);
        return sum;
    }
    
    void getSum(TreeNode* node, int cur_sum, int& sum) {
        if (!node->left && !node->right) {
            sum += (cur_sum*10 + node->val);
            return ;
        }
        
        cur_sum = cur_sum*10 + node->val;
        if (node->left)
            getSum(node->left, cur_sum, sum);
        
        if (node->right)
            getSum(node->right, cur_sum, sum);
    }
};