/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
    求一棵完成二叉树的node个数，要求时间复杂度低于O(N)
    思路：
    首先遍历整棵树的左边界，得到树的总高度，记为h（因为是完全二叉树，所以左边界的绝对在最后一层）。
    然后，遍历根节点的右孩子的左边界。这里有两种情况：
    1.如果右子树的左边界达到了最后一层，那么，左子树是满二叉树，左子树的高度为h-1，根据公式左子树一共有2^(h-1) - 1 个节点，再加上根节点，就一共2^(h-1)个节点。此时，把右子树当作一棵完成二叉树，递归处理。
    2.如果右子树的左边界没有达到最后一层，那么，右子树是满二叉树，右子树的高度为h-2，根绝公式右子树一共有2^(h-2) - 1 个节点，再加上根节点，就一共2^(h-2)个节点。此时，把左子树当作一棵完成二叉树，递归处理。

    时间复杂度是O((logN)^2)
    一个O(logN)是因为一共这么多层（递归要么处理左子树要么处理右子树），然后每次递归都要遍历他的右子树，也是O(logN)，所以是平方

*/
class Solution {
public:
    int getLeftHeight(TreeNode* root) {
        int h = 0;
        while (root) {
            ++h;
            root = root->left;
        }
        return h;
    }
    
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        
        if (!root->left)
            return 1;
        
        int height = getLeftHeight(root);
        int heightR = 1+getLeftHeight(root->right);
        
        if (height == heightR) {
            return (1 << height-1) + countNodes(root->right);
        } else {
            return (1 << heightR-1) + countNodes(root->left);
        }
    }
};