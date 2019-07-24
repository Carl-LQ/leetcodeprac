// 看了左神的书来找原题写了一下，但是好像效率很低，高赞答案还没看明白，抽空看

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        dp[coins.size()][0] = 0;
        for (int j = 0; j <= amount; ++j) {
            for (int i = coins.size()-1; i >= 0; --i) {
                dp[i][j] = dp[i+1][j];  // 下面的值即使无效也无所谓，不影响
                if (j-coins[i] >= 0 && dp[i][j-coins[i]] != -1) {
                    dp[i][j] = dp[i][j] == -1 ? dp[i][j-coins[i]]+1 : min(dp[i][j], dp[i][j-coins[i]]+1); // 下面的值无效的话，直接设置成左边的那个值+1，表示要用多一个面值为coins[i]的coin
                }
            }
        }
        return dp[0][amount];
    }
};

// brute force, 从index以后的面值都可以用
int f(vector<int>& coins, int index, int amount) {
    if (index == coins.size()) {
        return amount == 0 ? 0 : -1;
    }
    
    int res = -1;
    for (int i = 0; i*coins[index] <= amount; ++i) {
        int next = f(coins, index+1, amount-i*coins[index]);
        if (next != -1) {
            res = res == -1 ? next+i : min(res, next+i);
        }
    }
    return res;
}