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
    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return 0;
        
        // 以自己为头节点的整棵子树的路径数，加上以左/右孩子为根节点的整棵子树的情况
        return count(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    
    // 以root为头节点的子树，能够找到多少个和为sum的路径呢？
    int count(TreeNode* root, int sum) {
        if (!root)
            return 0;
        
        // 到自己这里就终止能否成为一条路径？如果到自己这里不能，那么继续往下走能否可以？
        return (root->val==sum ? 1 : 0) + count(root->left, sum-root->val) + count(root->right, sum-root->val);
    }
};

// 高赞回答，其实和左神的方法思路一样啦
public int pathSum(TreeNode root, int sum) {
    HashMap<Integer, Integer> preSum = new HashMap();
    preSum.put(0,1);
    return helper(root, 0, sum, preSum);
}

public int helper(TreeNode root, int currSum, int target, HashMap<Integer, Integer> preSum) {
    if (root == null) {
        return 0;
    }
    
    currSum += root.val;
    int res = preSum.getOrDefault(currSum - target, 0);
    preSum.put(currSum, preSum.getOrDefault(currSum, 0) + 1);
    
    res += helper(root.left, currSum, target, preSum) + helper(root.right, currSum, target, preSum);
    preSum.put(currSum, preSum.get(currSum) - 1);
    return res;
}


// 改编成cpp版本
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
    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return 0;
        
        unordered_map<int,int> um;
        um.insert(make_pair(0, 1)); // means we can get 0 without any nodes. inserting this value we wont miss those path that starts from the root node of the whole tree
        return getPath(root, sum, 0, um);
    }
    
    // unordered_map<preSum, count_paths>
    int getPath(TreeNode* root, int aim, int sum, unordered_map<int,int> &um) {
        if (!root)
            return 0;
        
        int res = 0;
        sum += root->val;
        auto it = um.find(sum-aim);
        if (it != um.end()) {
            res += it->second;
        }

        // 注意这里要先查找完再添加
        it = um.find(sum);
        if (it != um.end()) {
            ++it->second;
        } else {
            um.insert(make_pair(sum, 1));
        }
        
        res += getPath(root->left, aim, sum, um) + getPath(root->right, aim, sum, um);
        --um[sum];  // 一定有，不用erase，因为减到0也不会影响。
        return res;
    }
};
