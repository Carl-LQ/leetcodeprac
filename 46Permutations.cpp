// 比较典型的一道回溯的问题，参考了高赞回复记录下来的答案
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }
    
    // 从start位置开始往后排列组合，start之前的位置固定了。
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == nums.size()-1) {
            res.push_back(nums);
            return ;
        }
        
        for (int i = start; i < nums.size(); ++i) {
            swap(nums, start, i);
            backtrack(nums, start+1, res);  // 当前位置放好了，放下一个位置
            swap(nums, start, i);
        }
    }
    
    inline void swap(vector<int>& arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}; 