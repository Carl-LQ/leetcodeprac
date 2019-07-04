// 依然是写出暴力递归的方法先
int getWays(int n) {
	if (n == 0 || n == 1)
		return n;
	if (n == 2)
		return 2;

	return getWays(n-1)+getWays(n-2);
}


class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1 || n == 2)
            return n;
        
        vector<int> dp(n);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
    }
};