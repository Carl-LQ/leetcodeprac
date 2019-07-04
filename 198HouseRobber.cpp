class Solution {
public:
    int rob(vector<int>& nums) {
        if(!nums.size())
            return 0;
        
        if (nums.size() == 1)
            return nums[0];
        
        
        vector<int> dp(nums.size());
        dp[dp.size()-1] = nums[nums.size()-1];
        dp[dp.size()-2] = max(nums[nums.size()-1], nums[nums.size()-2]);
        
        for (int i = dp.size()-3; i >= 0; --i) {
            dp[i] = max(nums[i]+dp[i+2], dp[i+1]);
        }
        return dp[0];
    }
};

// brute force
int f(vector<int>& nums, int pos) {
    if (pos == nums.size()-1)
        return nums[nums.size()-1];
    
    if (pos == nums.size()-2)
        return max(nums[pos+1], nums[pos]);
    
    return max(nums[pos]+f(nums, pos+2), f(nums, pos+1));
}

// 参考了高赞回复以后，发现还可以优化空间，只需要用O(1)的空间
int rob(vector<int>& nums) {
    if(!nums.size())
        return 0;
    
    if (nums.size() == 1)
        return nums[0];
    
    int next1 = max(nums[nums.size()-1], nums[nums.size()-2]);  //后续第一个
    int next2 = nums[nums.size()-1];    //后续第二个

    for (int i = nums.size()-3; i >= 0; --i) {
        int temp = max(nums[i]+next2, next1);
        next2 = next1;
        next1 = temp;
    }
    return next1;
}