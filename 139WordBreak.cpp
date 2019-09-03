// 动态规划的题，只要s的某个index之前能搞掂，之后不需要管他是怎么搞掂的，可以有多种组合方法，但是只要能组合就可以的，后续过程并不关心，也就是无后效性。
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us;
        for (string str : wordDict) {
            us.insert(str);
        }
        
        vector<bool> dp(s.length(), false);     // dp[i] means whether s[0...i-1] in words
        dp[0] = true;
        
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = i-1; j >= 0; --j) {    // 从后往前找或许能快一点
                if (dp[j] && us.count(s.substr(j, i-j)) == 1) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.length()];
    }
};
