/** 
    try to make it much easier to understand.
    let's say two person, p0 and p1, if p0[0] - p0[1] < p1[0] - p1[1], it equals to p0[0] + p1[1] < p1[0] + p0[1], which means p0 to A and p1 to B is cheaper than vice verse.
*/
class Solution {
public:
    bool static cmp(vector<int> a1, vector<int> a2) {
        return a1[0]-a1[1] < a2[0]-a2[1];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), cmp);
        int res = 0;
        for (int i = 0; i < costs.size() / 2; ++i) {
            res += costs[i][0];
        }
        for (int i = costs.size() / 2; i < costs.size(); ++i) {
            res += costs[i][1];
        }
        return res;
    }
};