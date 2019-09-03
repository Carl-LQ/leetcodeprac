// 这道题是左神讲过的桶排序的一个应用，非常巧妙。书上416有非常详细的解释，如果忘了哪些细节可以重新翻看。
class Solution {
public:
    inline int getIndex(long n, long minVal, long maxVal, long len) {
        return (int) ((n-minVal)*len/(maxVal-minVal));
    }
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        
        int num_buckets = nums.size();
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int n : nums) {
            maxVal = max(n, maxVal);
            minVal = min(n, minVal);
        }
        if (maxVal == minVal)
            return 0;

        vector<bool> hasNum(num_buckets+1, false);
        vector<int> minValues(num_buckets+1, INT_MAX);
        vector<int> maxValues(num_buckets+1, INT_MIN);
        
        int index = 0;
        for (int n : nums) {
            index = getIndex(n, minVal, maxVal, num_buckets);
            minValues[index] = min(n, minValues[index]);
            maxValues[index] = max(n, maxValues[index]);
            hasNum[index] = true;
        }
        
        int res = INT_MIN;
        int lastMaxNum = maxValues[0];
        for (int i = 1; i <= num_buckets; ++i) {
            if (hasNum[i]) {
                res = max(res, minValues[i]-lastMaxNum);
                lastMaxNum = maxValues[i];
            }
        }
        return res;
    }
};