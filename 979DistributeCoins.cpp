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
    int distributeCoins(TreeNode* root) {
        int move = 0;
        minMoves(root, move);
        return move;
    }
    
    int minMoves(TreeNode* root, int& moves) {
        if (!root)
            return 0;
        
        int left = minMoves(root->left, moves);
        int right = minMoves(root->right, moves);
        moves += abs(left) + abs(right);
        return root->val - 1 + left + right;
    }
};

// 这道题也是想了好一会，层次遍历也想过，后序遍历也想过，没想好怎么处理返回值，看了下高赞votrubac的思路，我的妈呀太巧妙了，牛！
// 后序一定是会最新处理最近的节点的coins进行分配，因为会最早遇到同一个公共祖先，这样走的路径一定是最少的。我也想过公共祖先但是没写出来，太强了，赞！