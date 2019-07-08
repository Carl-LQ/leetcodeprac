/**
	这是我想到的方法，根据之前做的一道题找回文子串数量想过来的。这里主要是找到每个独立的等差数列，然后再逐一内部统计，用公式(len-1)*(len-2)/2来算出每个独立的等差数列一共有多少个子数列。
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3)
            return 0;
        return maximalAS(A, 0);
    }
    
    int maximalAS(vector<int>& A, int index) {
        if (index > A.size() - 3) {
            return 0;
        }
        int res = 0;
        int next_index = index+1;
        int diff = A[next_index++]-A[index];
        while (next_index < A.size() && A[next_index]-A[next_index-1] == diff) {
            ++next_index；
        }
        // 这里注意next_index是等差数列的最后一个数的下一个index了
        if (next_index - index > 2) {
            res += ((next_index-index-1)*(next_index-index-2)/2);
        } else {
            next_index = index + 1;
        }
        res += maximalAS(A, next_index);
        return res;
    }
};


/**
	下面是参考了高赞答案的dp解法。先尝试写出brute force吧
*/
int numberOfArithmeticSlices(vector<int>& A) {
	if (A.size() < 3)
		return 0;

	int res = 0;
	vector<int> dp(A.size(), 0);
	for (int i = 2; i < A.size(); ++i) {
		if (A[i]-A[i-1] == A[i-1]-A[i-2])
			dp[i] = dp[i-1]+1;		// 以i作为结尾的等差数列的个数，相当于把A[i] append to 以A[i-1]结尾的等差数列后面，看看等差数列有没有增加，如果前面本来就是等差数列，每增加一个位置，就会增加多个以A[i]结尾的等差子数列。
		res += dp[i];
	}
	return res;
}

// 由于形成等差数列的时候每次只需判断前面一个位置有没有形成等差数列，我们可以省掉空间。如果一直是等差数列，一直++；否则，断了的话就是0，也不影响。
int numberOfArithmeticSlices(vector<int>& A) {
    if (A.size() < 3)
        return 0;

    int res = 0;
    int count = 0;
    for (int i = 2; i < A.size(); ++i) {
        if (A[i]-A[i-1] == A[i-1]-A[i-2])
            ++count;
        else 
            count = 0;
        res += count;
    }
    return res;
}


