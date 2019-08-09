class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0)
            return res;
        int endR = matrix.size()-1;
        int endC = matrix[0].size()-1;
        int tR = 0, tC = 0, dR = endR, dC = endC;
        int i = 0, j = 0;
        while (tR <= dR && tC <= dC) {  // 要行和列都同时小于等于才行
            if (tR == dR) {
                for (j = tC; j <= dC; ++j)
                    res.push_back(matrix[tR][j]);
                break;
            } 
            if (tC == dC) {
                for (i = tR; i <= dR; ++i)
                    res.push_back(matrix[i][tC]);    
                break;
            }
            i = tR;
            j = tC;
            while (!(i == dR && j == dC)) {
                res.push_back(matrix[i][j]);
                i = j == dC ? i+1 : i;
                j = j == dC ? j : j+1;
            }
            
            while (!(i == tR && j == tC)) {
                res.push_back(matrix[i][j]);
                i = j == tC ? i-1 : i;
                j = j == tC ? j : j-1;
            }
            
            ++tR;
            ++tC;
            --dR;
            --dC;
        }
        return res;
    }
};