class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1, m = 0;
        while (l < r) {
            if (nums[l] < nums[r])
                break;
            m = l + (r - l >> 1);
            if (nums[m] >= nums[l]) {   // 当剩下两个的时候
                l = m + 1;
            } else {
                r = m;
            }
        }
        return nums[l];
    }
};