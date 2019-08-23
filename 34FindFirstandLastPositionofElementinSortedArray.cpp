class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int l = 0, r = nums.size()-1, m = 0;
        while (l <= r) {
            m = l + (r-l >> 1);
            if (nums[m] == target) {
                res[0] = findLeft(nums, l, m, target);
                res[1] = findRight(nums, m, r, target);
                break;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res;
    }
    
    int findLeft(vector<int>& nums, int l, int r, int t) {
        while (l <= r) {
            int m = l + (r-l >> 1);
            if (nums[m] < t) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
    
    int findRight(vector<int>& nums, int l, int r, int t) {
        while (l <= r) {
            int m = l + (r-l >> 1);
            if (nums[m] <= t) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return r;
    }
};