class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // vector<int> dp(days.size(), costs[0]);   // 本来是这样写的，但是testcase里面有弱智设定，一天的票价比七天的贵，迷。
        vector<int> dp(days.size(), min(min(costs[0], costs[1]), costs[2]));
        for (int d_index = days.size()-2; d_index >=0; --d_index) {
            if (days[days.size()-1] < days[d_index]+7) {
                dp[d_index] = min(costs[1], costs[0]+dp[d_index+1]);
                continue;
            }
            
            int next_index = d_index + 1;
            while (days[next_index] < days[d_index]+7) {
                ++next_index;   // the next day_index larger then dat[d_index]+7
            }
            if (days[days.size()-1] < days[d_index]+30) {
                dp[d_index] = min(min(costs[0]+dp[d_index+1], costs[1]+dp[next_index]), costs[2]);
                continue;
            }
            
            int next_month_index = next_index;
            while (days[next_month_index] < days[d_index]+30) {
                ++next_month_index;
            }
            dp[d_index] = min(min(costs[0]+dp[d_index+1], costs[1]+dp[next_index]), costs[2]+dp[next_month_index]);
        }
        return dp[0];
    }
};

// brute force。这里有一点需要注意的，既然是暴力递归了，那就不要在意太多约束条件能不能提前结束了，写一堆if反而会容易让代码更不清晰。
// 尽可能地把代码写简单，反正转换完dp的话也就一个简单的取值而已。
int f(vector<int>& days, vector<int>& costs, int d_index) {
    if (d_index == days.size()-1) {
        return costs[0];
    }
    
    if (days[days.size()-1] < days[d_index]+7) {
        return min(costs[1], costs[0] + f(days, costs, d_index+1));
    }
    
    int next_index = d_index + 1;
    while (days[next_index] < days[d_index]+7) {
        ++next_index;
    }
    if (days[days.size()-1] < days[d_index]+30) {
        return min(min(costs[2], costs[0] + f(days,costs,d_index+1)), costs[1] + f(days,costs, next_index));
    } 
    
    int next_month_index = next_index;
    while (days[next_month_index] < days[d_index]+30) {
        ++next_month_index;
    }
    return min(min(costs[2]+f(days, costs, next_month_index), costs[0]+f(days,costs,d_index+1)), costs[1]+f(days,costs, next_index)));
}