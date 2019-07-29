class Solution {
public:
    string board[6] = {
        "abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"
    };
    
    string alphabetBoardPath(string target) {
        string res = "";
        if (target.length() == 0)
            return res;
        res += moveFrom2End('a', target[0]);
        for (int i = 1; i < target.length(); ++i) {
            res += moveFrom2End(target[i-1], target[i]);
        }
        return res;
    }
    
    string moveFrom2End(char start, char end) {
        string res;
        int startLine = (start-'a') / 5;
        int endLine = (end-'a') / 5;
        bool flag = false;
        if (startLine != endLine && endLine == 5) {
            flag = true;
            --endLine;
        }
        
        if (startLine > endLine) {
            for (int i = 0; i < startLine-endLine; ++i) {
                res += "U";
            }
        } else if (startLine < endLine) {
            for (int i = 0; i < endLine-startLine; ++i) {
                res += "D";
            }
        }
        
        int startCol = (start-board[startLine][0]) % 5;
        int endCol = (end-board[endLine][0]) % 5;
        if (startCol > endCol) {
            for (int i = 0; i < startCol-endCol; ++i) {
                res += "L";
            }
        } else if (startCol < endCol) {
            for (int i = 0; i < endCol-startCol; ++i) {
                res += "R";
            }
        }
        
        if (flag) {
            res += "D";
        }
        
        res += "!";
        return res;
    }
};

// 老王滴～
class Solution {
public:
    string alphabetBoardPath(string target) {
        string move[26][26];
        for(size_t i = 0; i < 26; ++i) {
            for(size_t j = 0; j < 26; ++j) {
                string str = "";
                int x1 = i % 5, y1 = i / 5, x2 = j % 5, y2 = j / 5;
                if(i == 25) {
                    str += "U";
                    x1 = 0; y1 = 4;
                }
                if(x2 > x1) {
                    for (int t = x1; t < x2; ++t)
                        str += "R";
                } else {
                    for (int t = x1; t > x2; --t)
                        str += "L";
                }
                if(y2 > y1) {
                    for (int t = y1; t < y2; ++t)
                        str += "D";
                } else {
                    for (int t = y1; t > y2; --t)
                        str += "U";
                }
                str += "!";
                move[i][j] = str;
            }
        }
        move[25][25] = "!";
        char last = 'a';
        string ret = "";
        for(int i = 0; i < target.size(); ++i) {
            ret += move[last - 'a'][target[i] - 'a'];
            last = target[i];
        }
        return ret;
    }
};