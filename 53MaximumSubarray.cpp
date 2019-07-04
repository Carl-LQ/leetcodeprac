int originBruteForce(vector<int>& nums, int start) {
    if (start == nums.size()-1)
        return nums[start];

    return nums[start] + (originBruteForce(nums, start+1), 0);
}

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[nums.size()-1] = nums[nums.size()-1];
        int res = dp[nums.size()-1];
        for (int i = nums.size()-2; i >= 0; --i) {
            dp[i] = max(nums[i], nums[i]+dp[i+1]);
            res = max(res, dp[i]);
        }
        return res;
    }
};

// 这道题我不知道怎么脑子抽了，没想出来暴力递归的方法，直接写出了动态规划。下面参考了最高赞答案的回复，理解并写出了暴力递归的方法。

// brute force
/**
    主要是我们要加一个限制，简化问题，使得子问题比原问题小，却又能很容易的帮助原问题求出答案。这里就是以每个位置最为子数组的终止位置，然后求出哪个位置到该位置的sum最大。
*/

int maxSubArray(vector<int>& nums, int end) {
    if (end == 0) 
        return nums[0];

    return max(maxSubArray(nums, end - 1), 0) + nums[end];  // 如果前面是正数，加上；否则就是自己。
}

int getMax(vector<int>& nums) {
    return maxSubArray(nums, nums.size()-1);
}

// 如果根据这个brute force的话，就会改成从头开始的dp。我原本想的那个，可以理解为，固定开始的位置，然后改。补到了原来的上面。再写写着这种改法的dp，巩固一下。
int maxSubArray(vector<int>& nums) {
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int res = dp[0];
    for (int i = 1; i < nums.size(); ++i) {
        dp[i] = nums[i] + max(dp[i-1], 0);
        res = max(res, dp[i]);
    }
    return res;
}
// 好像这种顺序访问数组的要比逆序快一点？