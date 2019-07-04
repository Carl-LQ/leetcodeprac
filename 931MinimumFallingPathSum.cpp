// 非常典型的dp问题，下面是暴力递归，半伪代码，帮助我们找到规律即可
// min( f(A, 0, 0), f(A, 0, 1), ..., f(A, 0, A[0].size()-1) )
int f(vector<vector<int>>& A, int r, int c) {
    if (r == A.size()-1) {
        return A[r][c];
    }
    
    if (c == 0) {
        return A[r][c] + min(f(A, r+1, c), f(A, r+1, c+1));    
    } else if (c == A[0].size()-1) {
        return A[r][c] + min(f(A, r+1, c), f(A, r+1, c-1))
    } else {
        return A[r][c] + min(f(A, r+1, c-1), f(A, r+1, c), f(A, r+1, c+1));
    }
}

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        vector<vector<int> > dp(A.size(), vector<int>(A[0].size(), 0));
        for (int c = 0; c < A[0].size(); ++c) {
            dp[A.size()-1][c] = A[A.size()-1][c];
        }
        
        for (int r = A.size()-2; r >= 0; --r) {
            for (int c = 0; c < A[0].size(); ++c) {
                if (c == 0) {
                    dp[r][c] = A[r][c] + min(dp[r+1][c], dp[r+1][c+1]);    
                } else if (c == A[0].size()-1) {
                    dp[r][c] = A[r][c] + min(dp[r+1][c], dp[r+1][c-1]);
                } else {
                    dp[r][c] = A[r][c] + min(min(dp[r+1][c-1], dp[r+1][c]), dp[r+1][c+1]);
                }
            }
        }
        
        return *min_element(dp[0].begin(), dp[0].end());
    }
};

