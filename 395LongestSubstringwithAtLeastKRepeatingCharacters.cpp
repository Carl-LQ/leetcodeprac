// 这道题典型的有思路很难写，参考了高赞答案还是使用了比较暴力的方法。。。
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (k <= 1 || s.length() == 0)
            return s.length();
        
        int count[26] = {0};
        for (char c : s) {
            ++count[c-'a'];
        }
        bool flag = true;
        for (int i = 0; i < 26; ++i) {
            if (count[i] > 0 && count[i] < k)
                flag = false;
        }
        
        if (flag)
            return s.length();
        
        int begin = 0;
        int res = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (count[s[i]-'a'] > 0 && count[s[i]-'a'] < k) {
                res = max(res, longestSubstring(s.substr(begin, i-begin), k));
                while (i+1 < s.length() && count[s[i+1]-'a'] > 0 && count[s[i+1]-'a'] < k)
                    ++i;
                begin = i+1;
            }
        }
        res = max(res, longestSubstring(s.substr(begin), k));
        return res;
    }
};