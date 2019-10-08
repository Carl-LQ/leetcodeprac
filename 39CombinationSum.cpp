// 比较典型的回溯的问题，一开始还想着能不能用dp来做，因为看起来和找钱的题型有点像，虽然也是无后效性的问题，但实际上如果用dp的话我们可以快速求出有多少种方法，但是每一种具体的方法

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

