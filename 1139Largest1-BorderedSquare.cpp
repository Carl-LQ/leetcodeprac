class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int maxLen = 0;
        int width = grid[0].size();
        int height = grid.size();
        int hor[height][width], ver[height][width];
        for(int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j]) {
                    hor[i][j] = j == 0 ? 1 : hor[i][j-1]+1;
                    ver[i][j] = i == 0 ? 1 : ver[i-1][j]+1;
                } else {
                    hor[i][j] = 0;
                    ver[i][j] = 0;
                }
            }
        }
        
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int shorterLen = min(hor[i][j], ver[i][j]);
                while (shorterLen > maxLen) {
                    if (ver[i][j-shorterLen+1] >= shorterLen && 
                        hor[i-shorterLen+1][j] >= shorterLen) {
                        maxLen = shorterLen;
                    }
                    --shorterLen;
                }
            }
        }
        
        return maxLen*maxLen;
    }
    
};