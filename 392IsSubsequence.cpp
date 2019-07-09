// version 1
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() > t.length())
            return false;
        
        int s_index = 0;
        int t_index = 0;
        while (s_index < s.length() && t_index < t.length()) {
            if (s[s_index] == t[t_index]) {
                ++s_index;
                ++t_index;
            } else {
                ++t_index;
            }
        }
        if (s_index == s.length()) {
            return true;
        } else {
            return false;
        }
    }
};

// version 2: follow up question. 先预处理，扫描一遍t，然后把字符串出现的位置都记录在对应的数组中，以后再进行匹配的时候，就可以直接根据这个map来进行判断。
class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int> > indexs;
        for (int i = 0 ; i < t.length(); ++i) {
            indexs[t[i]].push_back(i);
        }
        
        int prev = -1;
        for (int i = 0; i < s.length(); ++i) {
            unordered_map<char, vector<int> >::iterator it = indexs.find(s[i]);
            if (it == indexs.end())
                return false;
            vector<int> v = it->second;
            int pos = upper_bound(v.begin(), v.end(), prev) - v.begin();
            if (pos == v.size())
                return false;
            prev = v[pos];
        }
        return true;
    }
};