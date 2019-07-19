class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    count = 0;
                    infect(grid, i, j, count);
                }
                res = max(res, count);
            }
        }
        return res;
    }
    
    void infect(vector<vector<int>>& grid, int i, int j, int& count) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) {
            return ;
        }
        
        ++count;
        grid[i][j] = 2;    
        infect(grid, i-1, j, count);
        infect(grid, i+1, j, count);
        infect(grid, i, j-1, count);
        infect(grid, i, j+1, count);
    }
};