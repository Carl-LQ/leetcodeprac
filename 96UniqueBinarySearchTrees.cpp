// dp[i] 表示i个节点有多少种不同的BST
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] += (dp[i-1] << 1);    // 自己作为头节点 + 以1作为头节点
            for (int j = i-1; j >= 2; --j) {    // 1是特例，因为没有dp[0]，但1单独拎出来很好想，就是d[i-1]种嘛
                dp[i] += dp[i-j]*dp[j-1];   // 以j作为头节点的时候，j到i之间一共（i-j）个点能组成多少种不同的BST，因为这j-i个点也是连续的，所以实际共dp[j-i]种
            }
        }
        return dp[n];
    }
};