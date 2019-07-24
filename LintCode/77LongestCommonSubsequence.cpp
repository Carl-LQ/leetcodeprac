// 最长公共子序列问题

class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        if (A.length() == 0 || B.length() == 0)
            return 0;
        // dp[i][j] means the LCS of str1[0...i] and str2[0...j]
        vector<vector<int>> dp(A.length(), vector<int>(B.length(), 0));
        
        dp[0][0] = A[0] == B[0] ? 1 : 0;
        
        // the first column
        for (int i = 1; i < A.length(); ++i) {
            dp[i][0] = max(dp[i-1][0], A[i] == B[0] ? 1 : 0);
        }
        
        // the first row
        for (int j = 1; j < B.length(); ++j) {
            dp[0][j] = max(dp[0][j-1], A[0] == B[j] ? 1 : 0);
        }
        
        for (int i = 1; i < A.length(); ++i) {
            for (int j = 1; j < B.length(); ++j) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(A[i] == B[j]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
                }
            }
        }
        
        return dp[A.length()-1][B.length()-1];
    }
};


// 我们拓展一下，如何返回这个公共的子串呢？
string getLCSe(string str1, string str2, vector<int>& dp) {
    // suppose we got the dp
    int row = str1.length()-1;
    int col = str2.length()-1;
    string res(dp[row][col]);
    int index = res.length()-1;
    while (index >= 0) {
        if (row > 0 && dp[row][col] == dp[row][col-1]) {
            --row;
        } else if (col > 0 && dp[row][col] == dp[row][col-1]) {
            --col;
        } else {
            res[index--] = str1[row];
            --row;
            --col;
        }
    }
    return res;
}