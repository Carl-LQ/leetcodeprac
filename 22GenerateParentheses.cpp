class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack("", n, n, res);
        return res;
    }
    
    // left # of '(' and left # of ')'
    void backtrack(string curStr, int n_left, int n_right, vector<string>& res) {
        if (n_left == 0 && n_right == 0) {
            res.push_back(curStr);
            return ;
        }
        if (n_left > 0) {
            backtrack(curStr+"(", n_left-1, n_right, res);
        }
        if (n_left < n_right) {
            backtrack(curStr+")", n_left, n_right-1, res);
        }
    }
};