class Solution {
public:
    int jump(vector<int>& nums) {
        int cur = 0;
        int step = 0;
        int next = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (cur < i) {
                ++step;
                cur = next;
                if (cur >= nums.size()-1)
                    break;
            }
            next = max(next, i+nums[i]);
        }
        return step;
    }
};