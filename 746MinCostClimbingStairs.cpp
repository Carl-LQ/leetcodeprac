// 写出暴力递归，再根据递归找规律改

class Solution {
public:
    // brute force version
//     int minCost(vector<int>& cost, int start) {
//         if (cost.size()-1 == start)
//             return cost[start];
        
//         if (cost.size()-2 == start)
//             return cost[start]+cost[start+1];
        
//         //if (cost.size()-2 > start)
//         return cost[start]+min(minCost(cost, start+1), minCost(cost, start+2));
//     }
    
    int minCostClimbingStairs(vector<int>& cost) {
        // return min(minCost(cost, 0), min(cost, 1));
        vector<int> totalcosts(cost.size(), 0);
        totalcosts[cost.size()-1] = cost[cost.size()-1];
        totalcosts[cost.size()-2] = cost[cost.size()-2];
        for (int i = cost.size()-3; i >= 0; --i) {
            totalcosts[i] = cost[i] + min(totalcosts[i+1], totalcosts[i+2]);
        }
        return min(totalcosts[0], totalcosts[1]);
    }
};