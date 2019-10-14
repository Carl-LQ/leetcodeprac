// 思路本来就是对每个因子记录一下个数这样的，但是想了会儿感觉越来越乱，参考了一下高赞回答，马上思路就清晰了，dp真是个神奇的东西。
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        decltype(dp.size()) idx2 = 0, idx3 = 0, idx5 = 0;
        for (int i = 1; i < n; ++i) {
            dp[i] = min(dp[idx2]*2, min(dp[idx3]*3, dp[idx5]*5));
            if (dp[i] == dp[idx2]*2) ++idx2;
            if (dp[i] == dp[idx3]*3) ++idx3;
            if (dp[i] == dp[idx5]*5) ++idx5;
        }
        return dp[n-1];
    }
};