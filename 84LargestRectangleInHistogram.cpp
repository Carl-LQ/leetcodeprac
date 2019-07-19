class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0)
            return 0;
        int res = 0;
        stack<int> indexes;
        for (int i = 0; i < heights.size(); ++i) {
            while (!indexes.empty() && heights[i] < heights[indexes.top()]) {
                int height = heights[indexes.top()];
                indexes.pop();
                int right = i-1;
                int left = indexes.empty() ? -1 : indexes.top();
                res = max(res, height*(right-left));
            }
            
            if (!indexes.empty() && heights[i] == heights[indexes.top()]) {
                indexes.pop();
            }
            indexes.push(i);
        }
        
        while (!indexes.empty()) {
            int height = heights[indexes.top()];
            indexes.pop();
            int right = heights.size()-1;
            int left = indexes.empty() ? -1 : indexes.top();
            res = max(res, height*(right-left));
        }
        return res;
    }
};