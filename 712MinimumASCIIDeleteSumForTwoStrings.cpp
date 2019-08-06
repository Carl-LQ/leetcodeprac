// 今天随机又pick到了这道题，之前不会的，不过隔了一两周了，重新看一下，最后还是写出来了，不过速度有点慢，耗了35分钟，主要是basecase那里耗了点时间。
// dp[i][j]代表s1[0...i]和s2[0...j]的最小删除的ASCII和。所以，根据这个意义，我们可以先求出第一列和第一行的dp:
// 第一行dp[0][j]表示s1[0]和s2[0...j]相比，如果s2[j] == s1[0]，那么在j之前，我们需要把s1[0]和s2所有的字符都删掉，在j及其之后的位置，只需要把s2的字符都删掉。
// 同理第一列dp[i][0]表示s1[0...i]和s2[0]相比，如果s1[i] == s2[0]，那么在i之前，我们需要把s1所有的字符和s2[0]都删除，在i及其之后的位置，s1遇到什么删什么。
// 对于一个普通的位置dp[i][j]，如果s1[i]==s2[j]，那么dp[i][j] = dp[i-1][j-1]；否则选择s1[i]和s2[j]中小的删除，dp[i][j] = min(s1[i]+dp[i-1][j], s2[j]+dp[i][j-1])。
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), 0));
        dp[0][0] = s1[0]==s2[0] ? 0 : s1[0]+s2[0];
        bool flag = dp[0][0] == 0 ? true : false;   // flag=true 表明已经找到了和s1[0]/s2[0]相同的了
        // 第一行
        for (int j = 1; j < s2.length(); ++j) {
            if (!flag && s1[0] == s2[j]) {    // 第一次找到
                dp[0][j] = dp[0][j-1] - s1[0];
                flag = true;
            } else {    // 之前已经找到了 或者 一直没找到
                dp[0][j] = dp[0][j-1] + s2[j];
            }
        }
        
        // 第一列
        flag = dp[0][0] == 0 ? true : false;
        for (int i = 1; i < s1.length(); ++i) {
            if (!flag && s1[i] == s2[0]) {
                dp[i][0] = dp[i-1][0] - s2[0];
                flag = true;
            } else {
                dp[i][0] = dp[i-1][0] + s1[i];
            }
        }
        
        for (int i = 1; i < s1.length(); ++i) {
            for (int j = 1; j < s2.length(); ++j) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(s1[i]+dp[i-1][j], s2[j]+dp[i][j-1]);
                }
            }
        }
        
        return dp[s1.length()-1][s2.length()-1];
    }
};

// 后面想了想，蹩脚优化:
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), 0));
        dp[0][0] = s1[0]==s2[0] ? 0 : s1[0]+s2[0];
        bool flag = dp[0][0] == 0 ? true : false;   // flag=true 表明已经找到了和s1[0]/s2[0]相同的了
        // 第一行
        for (int j = 1; j < s2.length(); ++j) {
            if (!flag && s1[0] == s2[j]) {    // 第一次找到
                dp[0][j] = dp[0][j-1] - s1[0];
                flag = true;
            } else {    // 之前已经找到了 或者 一直没找到
                dp[0][j] = dp[0][j-1] + s2[j];
            }
        }
        
        // 第一列
        flag = dp[0][0] == 0 ? true : false;
        for (int i = 1; i < s1.length(); ++i) {
            if (!flag && s1[i] == s2[0]) {
                dp[i][0] = dp[i-1][0] - s2[0];
                flag = true;
            } else {
                dp[i][0] = dp[i-1][0] + s1[i];
            }

            for (int j = 1; j < s2.length(); ++j) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(s1[i]+dp[i-1][j], s2[j]+dp[i][j-1]);
                }
            }
        }
        
        return dp[s1.length()-1][s2.length()-1];
    }
};

// 进一步优化空间，这个可是抠了好一会儿的：
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<int> dp(s2.length(), 0);
        dp[0] = s1[0] == s2[0] ? 0 : s1[0] + s2[0];
        bool flag = dp[0] == 0 ? true : false;   // flag=true 表明已经找到了和s1[0]相同的了
        // 第一行
        for (int j = 1; j < s2.length(); ++j) {
            if (!flag && s1[0] == s2[j]) {    // 第一次找到
                dp[j] = dp[j-1] - s1[0];
                flag = true;
            } else {    // 之前已经找到了 或者 一直没找到
                dp[j] = dp[j-1] + s2[j];
            }
        }
        
        // 第一列
        flag = dp[0] == 0 ? true : false;
        for (int i = 1; i < s1.length(); ++i) {
            int last_pre = dp[0];    // 需要记录上一行的前一个位置
            
            if (!flag && s1[i] == s2[0]) {
                dp[0] -= s2[0];
                flag = true;
            } else {
                dp[0] += s1[i];
            }
            
            for (int j = 1; j < s2.length(); ++j) {
                int last = dp[j];   // 上一行的当前位置
                if (s1[i] == s2[j]) {
                    dp[j] = last_pre;
                } else {
                    dp[j] = min(s1[i]+dp[j], s2[j]+dp[j-1]);
                }
                last_pre = last;
            }
        }
        return dp[s2.length()-1];
        
    }
};


//高赞答案，更加简洁，dp的定义变了，dp[i][j]表示s1[0...i-1]和s2[0...j-1]的字符串删除的ASCII之和
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int j = 1; j <= n; j++)
            dp[0][j] = dp[0][j-1]+s2[j-1];
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i-1][0]+s1[i-1];
            for (int j = 1; j <= n; j++) {
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = min(dp[i-1][j]+s1[i-1], dp[i][j-1]+s2[j-1]);
            }
        }
        return dp[m][n];
    }
};