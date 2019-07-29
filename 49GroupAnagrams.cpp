// 自己想的用hash还是容易冲突，没办法不排序，下面是sort版本的c++高赞答案，思想都是先对字符串进行一个排序，然后一样的对应一个vector，用map把两者联系起来。
// version 1
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};

// version 2，利用count sort加速
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        for (string s : strs) {
            um[countSort(s)].push_back(s);
        }
        
        vector<vector<string>> res;
        for (auto it : um) {
            res.push_back(it.second);
        }
        return res;
    }
    
    string countSort(string s) {
        int ch[26] = {0};
        for (char c : s) {
            ++ch[c-'a'];
        }
        string res = "";
        for (int i = 0; i < 26; ++i) {
            res += string(ch[i], 'a'+i);
        }
        return res;
    }
};