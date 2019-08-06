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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return true;
        
        if ((root1 && !root2) || (!root1 && root2))
            return false;
        
        if (root1->val != root2->val)
            return false;
        
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) || (flipEquiv(root1->right, root2->left) && flipEquiv(root1->left, root2->right));
    }
};

// 这道题一开始少了第二个basecase的判断条件，导致下面的递归写的很乱，要判断很多情况，可能太困了迷迷糊糊睡了个午觉，睡前好像想到了要这么改睡醒就写出来了- -
// 主要的收获就是basecase写完善一点可以省去很多判断的操作。不然下面要判断是否为左子树右子树是否为NULL等等，代码会很乱，直接只判断根节点，递归判断左子树和右子树就好，哎看来我递归的思想还是要多练练呀，还不算熟悉。