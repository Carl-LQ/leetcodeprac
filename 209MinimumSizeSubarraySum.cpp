class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int L = 0;
        int R = 0;
        int sum = 0;
        int res = INT_MAX;
        while (R < nums.size()) {
            sum += nums[R];
            while (sum >= s && L <= R) {
                res = min(res, R-L+1);
                sum -= nums[L++];
            }
            ++R;
        }
        if (res == INT_MAX)
            res = 0;
        return res;
    }
};