// 首先记录一下dfs的写法。这是看了高赞以后的改进，很清晰的思路，就是改变了原来的数据grid，而且时间复杂度有点高- -三次方吧估计- -
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, 1, true);
                }
            }
        }
        
        int md = -1;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] > 1) {
                    md = max(md, grid[i][j]-1);
                }
            }
        }
        
        return md;
    }
    
    void dfs(vector<vector<int>>& grid, int r, int c, int dis, bool isLand = false) {
        if (!isLand) {
            if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || (grid[r][c] != 0 && grid[r][c] <= dis)) {
                return ;
            }
            grid[r][c] = dis;
        }
        
        dfs(grid, r-1, c, dis+1);
        dfs(grid, r+1, c, dis+1);
        dfs(grid, r, c-1, dis+1);
        dfs(grid, r, c+1, dis+1);
    }
};