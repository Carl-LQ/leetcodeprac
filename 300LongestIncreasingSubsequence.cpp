// 这只是O(N^2)的解，而且不需要求解子序列，只需要长度
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        vector<int> dp(nums.size(), 1); // the LIS that end with nums[i]
        int res = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }
};

// 我们扩展一下题目，现在需要返回其中一个最长子序列
vector<int> LIS(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;
    
    vector<int> dp(nums.size(), 1); // the LIS that end with nums[i]
    int res = 1;
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j]+1);
                res = max(res, dp[i]);
            }
        }
    }
    return getLIS(nums, dp);
}


vector<int> getLIS(vector<int>& nums, vector<int>& dp) {
	int len = 0;
	int index = 0;
	for (int i = 0; i < dp.size(); ++i) {
		if (dp[i] > len) {
			len = dp[i];
			index = i;
		}
	}

	vector<int> lis(len);
	lis[--len] = nums[index];
	for (int i = index-1; i >= 0; --i) {
		if (nums[i] < nums[index] && dp[i] == dp[index]-1) {
			lis[--len] = nums[i];
			index = i;
		}
	}

	return lis;
}

// 上面的都是O(N^2)的时间复杂度，现在优化成O(NlogN)的时间复杂度，我们使用end数组和right来加速dp的求解，实际上end是一个数组，里面存着的每个数字代表长度为index+1的LIS的尾部的数字为多大。
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        vector<int> dp(nums.size(), 1); // the LIS that end with nums[i]
        vector<int> ends(nums.size());
        int right = 0;
        ends[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int l = 0;
            int r = right;
            while (l <= r) {
                int m = l + (r - l >> 1);
                if (ends[m] < nums[i]) {
                    l = m + 1;
                } else {    // if ends[m] >= nums[i], 所以即使是等于，也要把r设置为m-1，因为要找到从左边开始第一个大于等于nums[i]的。即便最后我们判断到了m-1位置还是等于，。
                    r = m - 1;
                }
            }
            right = max(right, l);
            ends[l] = nums[i];
            dp[i] = l+1;
        }
        return right+1;
    }
};