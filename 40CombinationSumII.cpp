class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> elem;
        backtrack(candidates, res, elem, target, 0);
        return res;
    }
    
    void backtrack(vector<int> &candidates, vector<vector<int>> &res, vector<int> &elem, int target, int beginIdx) {
        if (target == 0) {
            res.push_back(elem);
            return ;
        }
        
        for (int i = beginIdx; i < candidates.size() && candidates[i] <= target; ++i) {
            if (i > beginIdx && candidates[i] == candidates[i-1]) continue;
            elem.push_back(candidates[i]);
            backtrack(candidates, res, elem, target-candidates[i], i+1);
            elem.pop_back();
        }
    }
};