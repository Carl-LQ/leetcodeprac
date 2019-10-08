// 核心思想：弄一个新的matrix，每个位置每一行从左到该位置连续的1的个数，然后遍历每个位置，如果某个位置比当前记录的最大的连续的1的边还要大，那么从该位置开始向下判断是否有那么多行足够组成一个square
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        
        vector<vector<int>> rows(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        for (int i{0}; i < matrix.size(); ++i) {
            int consecutive{0};
            for (int j{0}; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == '0') {
                    consecutive = 0;
                } else {
                    rows[i][j] = ++consecutive;
                }
            }
        }
        
        int res{0};
        for (int i{0}; i < rows.size(); ++i) {
            for (int j{0}; j < rows[i].size(); ++j) {
                if (rows[i][j] > res) {
                    int k{i}, count{rows[k][j]};
                    for (; k < rows.size() && count > res && k < i+count; ++k) {
                        count = min(count, rows[k][j]);
                    }
                    if (k >= i+count)
                        res = max(res, count);
                }
            }
        }
        
        return res*res;
    }
};



// 参考了高赞答案以后的dp方法
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int res = 0;
        
        // set first line
        for (int j = 0; j < dp[0].size(); ++j) {
            dp[0][j] = matrix[0][j] - '0';
            res = max(res, dp[0][j]);
        }
        
        // set first column
        for (int i = 1; i < dp.size(); ++i) {
            dp[i][0] = matrix[i][0] - '0';
            res = max(res, dp[i][0]);
        }
        
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[i].size(); ++j) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
                res = max(res, dp[i][j]);
            }
        }
        
        return res*res;
    }
};


// dp方法可以进一步优化空间
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        
        vector<int> dp(matrix[0].size(), 0);
        int res = 0;
        for (int i = 0; i < dp.size(); ++i) {
            dp[i] = matrix[0][i] - '0';
            res = max(res, dp[i]);
        }
        
        for (int i = 1; i < matrix.size(); ++i) {
            int topleft{dp[0]};
            dp[0] = matrix[i][0] - '0';
            res = max(res, dp[0]);
            for (int j = 1; j < dp.size(); ++j) {
                int top{dp[j]};
                dp[j] = matrix[i][j] == '0' ? 0 : min(topleft, min(dp[j-1], dp[j])) + 1;
                topleft = top;
                res = max(res, dp[j]);
            }
        }
        
        return res*res;
    }
};