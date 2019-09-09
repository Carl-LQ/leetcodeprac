// 下面是参考了高赞回复以后整理出来的答案
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(t.length()+1, vector<long long>(s.length()+1, 1));
        for (int i = 0; i < t.length(); ++i) {
            dp[i+1][0] = 0;
            for (int j = 0; j < s.length(); ++j) {
                if (t[i] == s[j]) { // t[i]和s[j]最后一个字符相匹配 以及 不作为最后一个匹配
                    dp[i+1][j+1] = dp[i][j] + dp[i+1][j];
                } else {
                    dp[i+1][j+1] = dp[i+1][j];
                }
            }
        }
        return dp[t.length()][s.length()];
    }
};


// 下面是自己优化空间以后的答案
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<long long> dp(t.length()+1, 0);
        dp[0] = 1;
        for (int i = 0; i < s.length(); ++i) {
            int pre = dp[0];    // 其实可以直接写pre = 1; 但为了可读性
            for (int j = 0; j < t.length(); ++j) {
                int tmp = dp[j+1];
                if (s[i] == t[j]) {    // 只有相等的时候需要设置
                    dp[j+1] += pre;
                }
                pre = tmp;
            }
        }
        
        return dp[t.length()];
    }
};