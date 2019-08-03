// 这道题主要是借用了KMP算法的next数组，可以认为我在字符串的末尾添加了一个'#'结束符，然后每次都计算到结束符的位置，看看前面整个字符串的next数组的状况是怎么样的。
// 如果整个字符串是通过某个子串复制得到的，那么整个字符串的长度减去next[#]的值，剩余的那部分一定是重复的最小的单位子串，所以一定next[#]是他的整数倍。
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.length() <= 1) 
            return false;
        
        if (s.length() == 2)
            return s[0] == s[1];
        
        int len = s.length();
        int* next = new int[len+1];
        next[0] = -1;
        next[1] = 0;
        int i = 2;
        int cur = next[i-1];
        while (i <= len) {
            if (s[i-1] == s[cur]) {
                next[i++] = ++cur;
            } else if (cur > 0) {
                cur = next[cur];
            } else {
                next[i++] = 0;
            }
        }
        
        return next[len] && next[len] % (len-next[len]) == 0;
    }
};