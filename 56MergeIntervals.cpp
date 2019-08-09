class Solution {
public:
    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        if (v1[0] == v2[0])
            return v1[1] > v2[1];
        return v1[0] < v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), cmp);
        int start = 0, end = 0;
        size_t i = 0;
        bool flag = false;
        while (i < intervals.size()) {
            start = intervals[i][0];
            end = intervals[i][1];
            while (++i < intervals.size()) {
                if (intervals[i][0] <= end) {
                    end = max(end, intervals[i][1]);
                } else {
                    break;
                }
            }
            res.push_back({start, end});
        }
        return res;
    }
};