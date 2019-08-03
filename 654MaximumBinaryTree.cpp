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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return MBT(nums, 0, nums.size());
    }
    
    TreeNode* MBT(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return NULL;
        }
        int max_index = start;
        for (int i = start; i < end; ++i) {
            if (nums[i] > nums[max_index]) {
                max_index = i;
            }
        }
        TreeNode* root = new TreeNode(nums[max_index]);
        root->left = MBT(nums, start, max_index);
        root->right = MBT(nums, max_index+1, end);
        return root;
    }
};

// 上面那个是我写的垃圾O(N^2)的方法。看了高赞答案才惊醒原来能用单调栈结构！
// 从栈底到栈顶保持从大到小的顺序。如果当前栈不为空且栈顶元素比自己小，设置自己的left为栈顶元素，并弹出栈顶元素，继续进行当前判断，直到栈为空或者当前栈顶元素比自己大；如果栈不为空，那么代表栈顶元素比自己大使得判断条件终止，所以栈顶元素是数组中左边第一个比自己大的，所以自己暂时成为了栈顶元素的right（不是固定的，很有可能后面遇到比自己大的，把自己逼迫出来以后，自己就成为了那个元素的left，如果那个元素就成为了这个栈顶元素的right）
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> largeSt;
        for (int n : nums) {
            TreeNode* cur = new TreeNode(n);
            while(!largeSt.empty() && largeSt.top()->val < n) {
                cur->left = largeSt.top();
                largeSt.pop();
            }
            if (!largeSt.empty()) {
                largeSt.top()->right = cur;
            }
            largeSt.push(cur);
        }
        
        
        while(largeSt.size() > 1) {
            largeSt.pop();
        }
        return largeSt.top();
    }
};