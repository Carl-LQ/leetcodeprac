// 非常典型的一道回溯问题，因为固定了是从root到leaf，所以其实我们每次就在leaf的时候判断就好。

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        vector<int> path;
        getPath(root, sum, 0, path, res);
        return res;
    }
    
    void getPath(TreeNode* root, int aim, int preSum, vector<int> &path, vector<vector<int>> &res) {
        preSum += root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && preSum == aim) {
            res.push_back(path);
        }
        
        if (root->left) {
            getPath(root->left, aim, preSum, path, res);
        }
        if (root->right) {
            getPath(root->right, aim, preSum, path, res);
        }
        path.pop_back();
    }
};