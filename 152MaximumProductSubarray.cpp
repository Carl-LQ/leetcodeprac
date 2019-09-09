class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int minVal = 1;
        int maxVal = 1;
        int maxEnd = 0;
        int minEnd = 0;
        for (int n : nums) {
            minEnd = minVal * n;
            maxEnd = maxVal * n;
            minVal = min(n, min(minEnd, maxEnd));
            maxVal = max(n, max(minEnd, maxEnd));
            res = max(res, maxVal);
        }
        return res;
    }
};