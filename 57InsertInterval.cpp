class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        
        // before newInterval
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i++]);
        }
        
        if (i == intervals.size()) {
            res.push_back(newInterval);
            return res;
        }
        
        // insert newInterval
        int start_pos = min(newInterval[0], intervals[i][0]);
        int end_pos = min(newInterval[1], intervals[i][1]);
        if (end_pos >= intervals[i][0]) {   // if overlapped, end_pos set as the larger one
            end_pos = max(intervals[i][1], newInterval[1]);
        }
        while (i < intervals.size() && intervals[i][0] <= end_pos) {
            end_pos = max(end_pos, intervals[i++][1]);
        }
        res.push_back({start_pos, end_pos});
        
        // after newInterval
        while (i < intervals.size()) {
            res.push_back(intervals[i++]);
        }
        
        return res;
    }
};