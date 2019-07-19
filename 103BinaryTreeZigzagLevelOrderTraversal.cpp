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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        vector<int> elements;
        list<TreeNode*> dq;
        bool lr = true; // left->right
        TreeNode* nLast = NULL;
        TreeNode* last = root;
        dq.push_front(root);
        
        while (!dq.empty()) {
            if (lr) {
                root = dq.front();
                dq.pop_front();
                elements.push_back(root->val);
                if (root->left) {
                    if (!nLast) {
                        nLast = root->left;
                    }
                    dq.push_back(root->left);
                }
                
                if (root->right) {
                    if (!nLast) {
                        nLast = root->right;                        
                    }
                    dq.push_back(root->right);
                }
            } else {
                root = dq.back();
                dq.pop_back();
                elements.push_back(root->val);
                if (root->right) {
                    if (!nLast) {
                        nLast = root->right;
                    }
                    dq.push_front(root->right);
                }
                
                if (root->left) {
                    if (!nLast) {
                        nLast = root->left;
                    }
                    dq.push_front(root->left);
                }
            }
            
            if (root == last) {
                lr = !lr;
                last = nLast;
                nLast = NULL;
                res.push_back(elements);
                elements.clear();
            }
        }
        return res;
    }
};