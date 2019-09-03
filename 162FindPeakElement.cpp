class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        
        if (nums[0] > nums[1]) {
            return 0;
        } else if (nums[nums.size()-2] < nums[nums.size()-1]) {
            return nums.size()-1;
        }
        
        int l = 1, r = nums.size()-2, m = 0;
        while (l < r) {
            m = l + (r-l >> 1);
            if (nums[m] < nums[m-1]) {
                r = m - 1;
            } else if (nums[m] < nums[m+1]){
                l = m + 1;
            } else {
                return m;
            }
        }
        return l;
    }
};