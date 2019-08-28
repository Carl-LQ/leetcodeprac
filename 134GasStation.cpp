class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int minIndex = -1;
        int minValue = INT_MAX;
        for (int i = 0; i < gas.size(); ++i) {
            total += (gas[i]-cost[i]);
            if (total < minValue) {
                minIndex = i;
                minValue = total;
            }
        }
        
        return total < 0 ? -1 : (minIndex+1) % gas.size();
    }
};