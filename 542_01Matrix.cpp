// 这是我写的弱智版本，大体思路就是BFS，先加入所有的0，从0出发向周边扩展
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<int>> visit(matrix.size(), vector<int>(matrix[0].size(), 0));
        if (matrix.size() == 0) 
            return res;
        queue<vector<int>> q;   // vector[0]: #row, vector[1]: #column.
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0)
                    q.push({i,j});
                else
                    res[i][j] = INT_MAX;
            }
        }
        while (!q.empty()) {
            int row = q.front()[0];
            int column = q.front()[1];
            q.pop();
            if (visit[row][column] == 1)
                continue;
            visit[row][column] = 1;
            int left = column > 1 ? column-1 : 0;
            int right = column < matrix[0].size()-1 ? column+1 : matrix[0].size()-1;
            int top = row > 1 ? row-1 : 0;
            int bottom = row < matrix.size()-1 ? row+1 : matrix.size()-1;
            if (matrix[row][column] != 0) {
                if (row == top) {
                    if (left == column) {   // left-top
                        res[row][column] = min(res[row][right], res[bottom][column]) + 1;
                    } else {    // the first line
                        res[row][column] = min(min(res[row][right], res[bottom][column]), res[row][left])+ 1;
                    }
                } else if (row == bottom) {
                    if (left == column) {   // left-bottom
                        res[row][column] = min(res[row][right], res[top][column]) + 1;
                    } else {    // the last line
                        res[row][column] = min(min(res[row][right], res[top][column]), res[row][left]) + 1;
                    }
                } else {
                    res[row][column] = min(min(min(res[row][right], res[top][column]), res[row][left]), res[bottom][column]) + 1;
                }
            }
            q.push({row, left});
            q.push({row, right});
            q.push({top, column});
            q.push({bottom, column});
        }
        return res;
    }
};


// 下面是从左上角出发往右下角扫，这个过程中，一个位置的值只有他左边和上边决定。所以，我们还需要从右下角往左上角再扫一遍，这样他的值就由他的右边和下边决定了，所以两遍扫描就可以完全决定一个位置的值。
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), INT_MAX-10000));   // 这里INT_MAX-10000是因为第一遍扫描的时候要res[i-1][j]+1可能会overflow，其实-1就可以啦
        for(int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    res[i][j] = 0;                    
                } else {
                    if (i > 0)
                        res[i][j] = min(res[i][j], res[i-1][j]+1);
                    if (j > 0)
                        res[i][j] = min(res[i][j], res[i][j-1]+1);
                }
            }
        }
        
        for(int i = matrix.size()-1; i >= 0; --i) {
            for (int j = matrix[0].size()-1; j >= 0; --j) {                
                if (i < matrix.size()-1)
                    res[i][j] = min(res[i][j], res[i+1][j]+1);
                if (j < matrix[0].size()-1)
                    res[i][j] = min(res[i][j], res[i][j+1]+1);
            }
        }
        return res;
    }
};