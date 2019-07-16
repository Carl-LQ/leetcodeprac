// 这是我想的O(m+n) space 的方法
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> row(matrix.size(), false);     // true: set zero
        vector<bool> col(matrix[0].size(), false);  // true: set zero
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        
        for (int i = 0; i < row.size(); ++i) {
            if (row[i]) {
                for (int j = 0; j < col.size(); ++j)
                    matrix[i][j] = 0;
            }
        }
        
        for (int j = 0; j < col.size(); ++j) {
            if (col[j]) {
                for (int i = 0; i < row.size(); ++i)
                    matrix[i][j] = 0;
            }
        }
    }
};

// 这是参考了高赞答案的方法，O(1) space，主要是利用了原来数组的空间，时间上也是两次遍历
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstCol = false; // true to set first column zero
        
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0)
                firstCol = true;
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // bottom-up，主要是避免了从头开始，因为头的数据已经不能正确反映原来的数据了
        for (int i = matrix.size()-1; i >= 0; --i) {
            for (int j = matrix[0].size()-1; j >= 1; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (firstCol) {
                matrix[i][0] = 0;
            }
        }
    }
};