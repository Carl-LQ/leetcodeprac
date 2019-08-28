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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if (root)
            que.push(root);
        
        TreeNode* cur = NULL;
        int size = 0;
        while (!que.empty()) {
            size = que.size();
            vector<int> elem(size, 0);
            for (int i = 0; i < size; ++i) {
                cur = que.front();
                que.pop();
                elem[i] = cur->val;
                if (cur->left) 
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
            res.push_back(elem);
        }
        return res;
    }
};