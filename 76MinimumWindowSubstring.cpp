class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() == 0)
            return "";
        unordered_map<char, int> um;
        for (char c : t) {
            ++um[c];
        }
        int count = um.size();

        int L = 0, R = -1;
        int res = INT_MAX;
        int start = -1;
        auto it = um.begin();
        while (R < (int)s.length()) {   // 这里搞了我5min，我说咋不进这个循环，length得到的是无符号，会把R的-1当作无符号来看，所以R就很大了。
            ++R;
            it = um.find(s[R]);
            if (it != um.end()) {
                --it->second;
                if (it->second == 0)
                    --count;
            }

            while (count == 0) {
                if (R-L+1 < res) {
                    res = R-L+1;
                    start = L;
                }
                it = um.find(s[L]);
                if (it != um.end()) {
                    ++it->second;
                    if (it->second == 1)
                        ++count;
                }
                ++L;
            }
        }

        if (start != -1) {
            return s.substr(start, res);
        }
        return "";
    }
};