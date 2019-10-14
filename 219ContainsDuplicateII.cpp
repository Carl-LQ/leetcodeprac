class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() == 0 || k <= 0)
            return false;
        
        int l{0}, r{1};
        unordered_set<int> dict;
        for (; r <= k && r < nums.size(); ++r) {
            if (dict.count(nums[r]) == 1) {
                return true;
            } else {
                dict.insert(nums[r]);
            }
        }
        
        while (l < nums.size()-1) {
            if (dict.count(nums[l]) == 1) {
                return true;
            }
            dict.erase(nums[++l]);
            
            if (r < nums.size()) {
                if (dict.count(nums[r]) == 1) {
                    return true;
                } else {
                    dict.insert(nums[r]);
                }
                ++r;
            }

        }
        
        return false;
    }
};