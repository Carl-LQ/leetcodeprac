// 仔细想了一下，这道题就是求最长公共子序列的长度嘛- -
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.length() == 0 || word2.length() == 0) {
            return word1.length()+word2.length();
        }
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), 0));
        dp[0][0] = word1[0]==word2[0] ? 1 : 0;
        // the first column
        for (int i = 1; i < word1.length(); ++i) {
            dp[i][0] = word1[i] == word2[0] ? 1 : dp[i-1][0];
        }
        
        // the first row
        for (int j = 1; j < word2.length(); ++j) {
            dp[0][j] = word1[0] == word2[j] ? 1 : dp[0][j-1];
        }
    
        
        for (int i = 1; i < word1.length(); ++i) {
            for (int j = 1; j < word2.length(); ++j) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (word1[i] == word2[j]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
                }
            }
        }
        
        return word1.length()+word2.length()-(dp[word1.length()-1][word2.length()-1]<<1);
    }
};

// 顺手一波优化，莫名时间也减少了，空间也减少了，很迷- -明明只是优化空间
class Solution {
public:
    
    int minDistance(string word1, string word2) {
        if (word1.length() == 0 || word2.length() == 0) {
            return word1.length()+word2.length();
        }
        
        vector<int> dp(word2.length(), 0);
        dp[0] = word1[0] == word2[0];
        for (int j = 1; j < word2.length(); ++j) {
            dp[j] = word1[0] == word2[j] ? 1 : dp[j-1];
        }
            
        for (int i = 1; i < word1.length(); ++i) {
            int UpLeft = dp[0];
            dp[0] = word1[i] == word2[0] ? 1 : dp[0];
            for (int j = 1; j < word2.length(); ++j) {
                int tmp2 = dp[j];
                dp[j] = max(dp[j-1], dp[j]);
                if (word1[i] == word2[j]) {
                    dp[j] = max(UpLeft+1, dp[j]);
                }
                UpLeft = tmp2;
            }
        }
        
        return word1.length()+word2.length()-(dp[word2.length()-1]<<1);
    
    }
};