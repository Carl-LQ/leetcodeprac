// 睡觉前想到的思路，没想到早上起来整理一下还真的对了哈哈哈。
// 从后往前找非递减，一直找到比后面的数小的第一个的位置的时候，停下来，二分寻找后面那坨非递减的数中第一个比他大的，然后交换，然后再对后面这坨数字进行reverse即可。
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while (i >= 0 && nums[i] >= nums[i+1]) --i;
        if (i < 0) {
            reverseArr(nums, 0, nums.size()-1);
            return ;
        }
        
        int tmp = nums[i];
        int l = i+1, r = nums.size()-1, m = 0;
        while (l <= r) {
            m = l + (r-l >> 1);
            if (nums[m] <= tmp) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        nums[i] = nums[r];
        nums[r] = tmp;
        
        reverseArr(nums, i+1, nums.size()-1);
        
    }
    
    void reverseArr(vector<int>& nums, int l, int r) {
        for (; l < r && nums[l] != nums[r]; ++l, --r) {
            int tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
        }
    }
};