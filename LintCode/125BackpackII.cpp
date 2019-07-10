// - -其实这道题和I没有区别。。。
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int max_index = A.size();
        vector<int> dp(m+1, 0);
        for (int size = A[max_index-1]; size < m+1; ++size) {
            dp[size] = V[max_index-1];
        }
        
        for (int i = max_index-2; i >= 0; --i) {
            for (int size = m; size >= 0; --size) {
                if (size >= A[i]) {
                    dp[size] = max(V[i]+dp[size-A[i]], dp[size]);
                }
            }
        }
        
        return dp[m];
    }
};