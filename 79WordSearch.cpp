class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word == "")
            return true;
        int direction[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} }; // {nx, ny}, up/down/right/left
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), true));
        for (int y = 0; y < board.size(); ++y) {
            for (int x = 0; x < board[y].size(); ++x) {
                if (findWord(board, word, "", y, x, direction, visit, 0))
                    return true;
            }
        }
        return false;
    }
    
    // 一定要一个字母一个字母的比较，因为这样哪里对不上了直接断了这次的搜索，也是一个很简单的剪枝操作啦。
    bool findWord(vector<vector<char>>& board, string& word, string cur_str, int y, int x, int dir[4][2], vector<vector<bool>>& visit, int word_index) {
        if (word_index == word.length()) 
            return true;
        
        if (x < 0 || y < 0 || x == board[0].size() || y == board.size() || !visit[y][x] || board[y][x] != word[word_index])
            return false;
        
        visit[y][x] = false;
        int nx = 0, ny = 0;
        for (int i = 0; i < 4; ++i) {
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            if (findWord(board, word, cur_str, ny, nx, dir, visit, word_index+1))
                return true;
        }
        visit[y][x] = true;
        return false;
    }
};