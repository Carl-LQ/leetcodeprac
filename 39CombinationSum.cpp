class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> elem;
        backtrack(candidates, target, 0, elem, res);
        return res;
    }
    
    void backtrack(vector<int>& candidates, int target, int index, vector<int>& elem, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(elem);
            return ;
        }

        for (int i = index; i < candidates.size() && target >= candidates[i]; ++i) {
            elem.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i], i, elem, res);
            elem.pop_back();
        }

    }
};

