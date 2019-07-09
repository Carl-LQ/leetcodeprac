#include <iostream>
#include <vector>

using namespace std;

// now it's at arr[row][column]
int getWays(vector<vector<int> >& arr, int row, int column) {
	if (row == arr.size()-1 || column == arr[0].size()-1) {
		return 1;
	}

	return getWays(arr, row+1, column) + getWays(arr, row, column+1);
}

int getWays_dp(vector<vector<int> >& arr) {
	vector<vector<int> > dp(arr.size(), vector<int>(arr[0].size(), 0));
	for (int i = 0; i < dp[0].size(); ++i) {
		dp[dp.size()-1][i] = 1;
	}

	for (int i = 0; i < dp.size(); ++i) {
		dp[i][dp[0].size()-1] = 1;
	}

	for (int row = dp.size()-2; row >= 0; --row) {
		for (int column = dp[0].size()-2; column >= 0; --column) {
			dp[row][column] = dp[row+1][column] + dp[row][column+1];
		}
	}
	return dp[0][0];
}

// 实际平台上最终答案为：
class Solution {
public:
    /**
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n) {
        // write your code here
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
    		dp[m-1][i] = 1;
    	}
    
    	for (int i = 0; i < m; ++i) {
    		dp[i][n-1] = 1;
    	}
    
    	for (int row = m-2; row >= 0; --row) {
    		for (int column = n-2; column >= 0; --column) {
    			dp[row][column] = dp[row+1][column] + dp[row][column+1];
    		}
    	}
    	return dp[0][0];
    }
};

// 这道题还可以直接用公式！m行n列，一共要向下走m-1次，向右走n-1次，所以，用到排列组合！在总共的(m-1+n-1)中选择出n-1个位置放置向右走即可！所以是C(n-1,m+n-2)

