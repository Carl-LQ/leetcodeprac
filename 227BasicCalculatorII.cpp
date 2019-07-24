// 这是我写的最基础的版本，是看了左神那道题（加强版）写出来的，貌似效率有点低
class Solution {
public:
    void addNum(list<string>& dq, int num) {
        if (!dq.empty()) {
            string op = dq.back();
            if (op == "*" || op == "/") {
                dq.pop_back();
                int n = stoi(dq.back());
                dq.pop_back();
                num = op == "*" ? n*num : n/num;
            }
        }
        dq.push_back(to_string(num));
    }
    
    int calculate(string s) {
        list<string> dq;
        int pre = 0;
        int i = 0;
        while (i < s.length()) {
            if (s[i] == ' ') {
                ++i;
                continue;
            } else if (s[i] <= '9' && s[i] >= '0') {
                pre = pre*10 + (s[i++]-'0');    // 这里s[i++]-'0'要括起来，因为可能会溢出如果不括起来
            } else {
                addNum(dq, pre);
                dq.push_back(string(1, s[i++]));
                pre = 0;    // 重要，需要置零
            }
        }
        addNum(dq, pre);
        
        int res = 0;
        bool add = true;    // 重要，一开始默认是true，如果有-号的话会纠正过来的，但这道题没有负数
        string cur = "";
        int n = 0;
        while (!dq.empty()) {
            cur = dq.front();
            dq.pop_front();
            if (cur == "+") {
                add = true;
            } else if (cur == "-") {
                add = false;
            } else {
                n = stoi(cur);
                res += add ? n : (-n); 
            }
        }
        
        return res;
    }
};