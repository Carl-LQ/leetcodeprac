// 和15很像，改一下逻辑就好啦
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        int res = 0;
        int i = 0;
        int L = 0, R = 0;
        while (i < nums.size()) {
            L = i + 1;
            R = nums.size() - 1;
            while (L < R) {
                int sum = nums[i]+nums[L]+nums[R];
                if (sum == target) {
                    return sum;
                } else {
                    if (abs(sum-target) < minDiff) {
                        minDiff = abs(sum-target);
                        res = sum;
                    }
                    if (sum < target) {
                        while (++L < R && nums[L] == nums[L-1]) ;
                    } else {
                        while (L < --R && nums[R] == nums[R+1]) ;
                    }
                }
            }
            
            while (++i < nums.size() && nums[i] == nums[i-1]) ;
        }
        return res;
    }
};