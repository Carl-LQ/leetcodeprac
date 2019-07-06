// 这道题，想出来了，但是巨坑，调了半天发现是类型int太小了，要改成long long的，看来我还是低估路径的数目了。。。
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long> > dp(m, vector<long long>(n, 0));
        
        dp[m-1][n-1] = obstacleGrid[m-1][n-1]^1;
        
        for (int c = n-2; c >= 0; --c) {
            dp[m-1][c] = dp[m-1][c+1] & (obstacleGrid[m-1][c]^1);
            if(dp[m-1][c] == 0) // 由于默认设置为0，一旦为0，也不用设置了，这条路都不通了
                break;
        }
        
        for (int r = m-2; r >= 0; --r) {
            dp[r][n-1] = dp[r+1][n-1] & (obstacleGrid[r][n-1]^1);
            if(dp[r][n-1] == 0) // 由于默认设置为0，一旦为0，也不用设置了，这条路都不通了
                break;
        }
        
        for (int i = m-2; i >= 0; --i) {
            for (int j = n-2; j >= 0; --j) {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};


// brute force
int f(int r, int c) {
    if (r == obstacleGrid.size()-1 && c == obstacleGrid[0].size()-1) {
        return 1;
    } 
    if (obstacleGrid[r][c] == 1) 
        return 0;
    
    if (r==obstacleGrid.size()-1) { // 即使走到了最后一行，也还是要判断后面能否走通呢
        return f(r, c+1);
    }
    if (c == obstacleGrid[0].size()-1) { // 即使走到了最后一列，也还是要判断后面能否走通呢
        return f(r+1, c);
    }
    
    return f(r+1, c) + f(r,c+1);
}