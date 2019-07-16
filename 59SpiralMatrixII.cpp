class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int tR = 0;
        int tC = 0;
        int dR = n-1;
        int dC = n-1;
        int num = 1;
        while (tR <= dR) {
            if (tR == dR) {
                res[tR][tC] = num;
                break;
            }
            int i = tR;
            int j = tC;
            while (j < dC) {
                res[i][j++] = num++;
            }
            
            while (i < dR) {
                res[i++][j] = num++;
            }
    
            while (j > tC) {
                res[i][j--] = num++;
            }
            
            while(i > tR) {
                res[i--][j] = num++;
            }
            ++tR;
            ++tC;
            --dR;
            --dC;
        }
        return res;
    }
};