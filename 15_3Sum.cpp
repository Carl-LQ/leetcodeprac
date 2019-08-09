// 先排序，然后固定第一个位置，就变成了2sum的问题了，用双指针从后面的两边开始找和为目标sum减去第一个位置的数的差值。然后有一个加快速度的去重方法，因为已经排好序了，所以从头和尾可以跳过一些刚刚已经加入结果数组中的值。
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int target = -nums[i];
            int L = i+1;
            int R = nums.size()-1;
            while (L < R) {
                int sum = nums[L] + nums[R];
                if (sum == target) {
                    res.push_back({nums[i], nums[L++], nums[R--]});
                    while (L < R && nums[L] == nums[L-1]) ++L;  // 跳过第二位相同的值，否则没意义，浪费时间
                    while (L < R && nums[R] == nums[R+1]) --R;  // 第一个不变，第二个不同了，那第三个肯定也不同了，所以也可以跳过重复的值。
                } else if (sum < target) {
                    ++L;
                } else {
                    --R;
                }
            }
            
            while (i+1 < nums.size() && nums[i+1] == nums[i]) ++i;  // 跳过第一位重复的值
        }
        return res;
    }
};
