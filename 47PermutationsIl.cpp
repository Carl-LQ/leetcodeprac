// 根据46的逻辑简单改了一下下，用set来过滤掉重复的答案，但是效果一般，现在想改成用一个visit，但是还没想好。。。
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> s;
        backtrack(nums, 0, s);
        for (auto i : s) {
            res.push_back(i);
        }
        return res;
    }
    
    void backtrack(vector<int>& nums, int begin, set<vector<int>>& s) {
        if (begin == nums.size()) {
            s.insert(nums);
            return ;
        }
        
        for (int i = begin; i < nums.size(); ++i) {
            if (i != begin && nums[i] == nums[begin]) {
                continue;
            }
            swap(nums, begin, i);
            backtrack(nums, begin+1, s);
            swap(nums, begin, i);
        }
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};