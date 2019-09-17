// 我是直接交换了两个node的值- -看来这都能过，如果要直接交换节点的话，就比较麻烦了。。。好多情况要判断，我绕晕了
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* mostRight = NULL;
        TreeNode* pre = NULL;
        TreeNode* n1 = NULL;
        TreeNode* n2 = NULL;
        while (root) {
            mostRight = root->left;
            if (mostRight) {
                while (mostRight->right && mostRight->right != root) {
                    mostRight = mostRight->right;
                }
                if (mostRight->right != root) {
                    mostRight->right = root;
                    root = root->left;
                    continue;
                } else {
                    mostRight->right = NULL;
                }
            }
            if (pre && pre->val > root->val) {
                n1 = n1 == NULL ? pre : n1;
                n2 = root;
            }
            pre = root;
            root = root->right;
        }
        
        int tmp = n1->val;
        n1->val = n2->val;
        n2->val = tmp;
    }
};