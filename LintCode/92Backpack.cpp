class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        vector<vector<int>> dp(A.size(), vector<int>(m+1, 0));
        
        for (int j = A[A.size()-1]; j < m+1; ++j) {
            dp[A.size()-1][j] = A[A.size()-1];
        }
        
        for (int i = A.size()-2; i >= 0; --i) {
            for(int j = 1; j <= m; ++j) {
                if (j >= A[i]) {
                    dp[i][j] = max(A[i]+dp[i+1][j-A[i]], dp[i+1][j]);
                } else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        
        return dp[0][m];
        
    }


    // version 2: the space complexity is O(m)，优化了空间，因为发现了每行的结果之和下一行有关系，所以我们从下往上计算就好。
    int backPack2(int m, vector<int> &A) {
        vector<int> dp(m+1, 0);
        for (int j = A[A.size()-1]; j < m+1; ++j) {
            dp[j] = A[A.size()-1];
        }

        for (int i = A.size()-2; i >= 0; --i) {
            for (int j = m; j >= 0; --j) { //注意，由于我们要用到下一行前面的位置，所以每一行的计算顺序不像二维表一样可以从左到右，而是要从右到左，否则前面的先计算了就覆盖了上一行的信息了。
                if (j >= A[i]) {
                    dp[j] = max(A[i]+dp[j-A[i]], dp[j]);
                }
            }
        }
        return dp[m];
    }
};

// brute force，这是暴力递归的方法，要或者不要第i号物品。
int f(int m, vector<int> &A, int index) {
    if (index == A.size()-1)
        return A[index] > m ? 0 : A[index];

    if (m >= A[index]) {    // 要index号物品和不要index号物品，比较哪个能装的多
        return max(A[index] + f(m-A[index], A, index+1), f(m, A, index+1));
    } else {
        return f(m, A, index+1);
    }
}
