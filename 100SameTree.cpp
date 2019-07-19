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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string st1 = serializedTreeByPreOrder(p);
        string st2 = serializedTreeByPreOrder(q);
        return st1 == st2;
    }
    string serializedTreeByPreOrder(TreeNode* t) {
        if (!t) 
            return "#!";
        
        string res = to_string(t->val)+"!";
        res += serializedTreeByPreOrder(t->left);
        res += serializedTreeByPreOrder(t->right);
        return res;
    }
};

// 因为看过左神的序列化一棵树的操作，我先入为主写了这个方法，还有一些比较简洁的递归的方法，树的题感觉基本用递归都非常好写。。。
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}