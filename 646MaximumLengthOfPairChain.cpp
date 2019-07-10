// 这道题我没想到dp，想了一下感觉更像是贪心，就按照end时间从小到大排序，每次选完就往后找，找到第一个start时间比当前end时间大的，结果加一，更新end时间，然后重复上述操作。
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.size() == 0)
            return 0;
        vector<vector<int>> e (pairs.size(), vector<int>(2,0));
        for (int i = 0; i < pairs.size(); ++i) {
            e[i].assign(pairs[i].begin(), pairs[i].end());
        }
        sort(e.begin(), e.end(), cmp_end);
        int end_index = 1;
        int end_value = e[0][1];
        int res = 1;
        while (end_index < e.size()) {
            if (e[end_index][0] > end_value) {
                ++res;
                end_value = e[end_index][1];
            }
            ++end_index;
        }
        return res;
    }
    static bool cmp_end(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
    }
};
