class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (!grid.size())
            return 0;

        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        int row = grid.size() - 1;
        int column = grid[0].size() - 1;
        dp[row][column] = grid[row][column];
        for (int i = row - 1; i >= 0; --i) {
            dp[i][column] = grid[i][column] + dp[i+1][column];
        }
        if (column == 0)
            return dp[0][0];
        
        for (int j = column - 1; j >= 0; --j) {
            dp[row][j] = grid[row][j] + dp[row][j+1];
        }
        if (row == 0)
            return dp[0][0];
        
        while (--row >= 0 && --column >= 0) {
            for (int i = row; i >= 0; --i) {
                dp[i][column] = grid[i][column] + min(dp[i+1][column], dp[i][column+1]);
            }
            for(int j = column; j >= 0; --j) {
                dp[row][j] = grid[row][j] + min(dp[row][j+1], dp[row+1][j]);
            }
        }
        if (row > 0) {
            for (int i = row; i >= 0; --i) {
                dp[i][0] = grid[i][0] + min(dp[i][1], dp[i+1][0]);
            }
        }
        
        if (--column > 0)
            for (int j = column; j >= 0; --j) 
                dp[0][j] = grid[0][j] + min(dp[1][j], dp[0][j+1]);
        
        return dp[0][0];
    }
};