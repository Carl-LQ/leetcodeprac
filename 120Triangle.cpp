class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size(), 0);
        for (int i = 0; i < triangle.size(); ++i) {
            int tmp1 = dp[0];
            dp[0] += triangle[i][0];
            for (int j = 1; j < i; ++j) {
                int tmp2 = dp[j];
                dp[j] = min(tmp1, dp[j]) + triangle[i][j];
                tmp1 = tmp2;
            }
            dp[i] = tmp1 + triangle[i][i];
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};

