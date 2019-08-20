// 非常简单经典的回溯，主要练练回溯的思路。
class Solution {
public:
    string strs[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0)
            return res;
        bt(digits, 0, "", res);
        return res;
    }
    
    void bt(string digits, int start, string cur, vector<string>& res) {
        if (start == digits.length()) {
            res.push_back(cur);
            return ;
        }
        
        for (char c : strs[digits[start]-'2']) {
            bt(digits, start+1, cur+string(1,c), res);
        }
    }
};