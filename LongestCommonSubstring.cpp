// 最长公共子串问题。 和最长公共子序列不同，子串要求是连续的，有了这个条件以后，往往空间可以被优化成O(1)。下面我们先看看普通的O(N*M)的方法
// dp[i][j]意味着以str1[i]和str2[j]作为公共子串的最后一位的情况下，公共子串有多长。很显然，str1[i] != str2[j]的时候，dp[i][j]=0
// basecase的话也是先看第一行和第一列。

vector<vector<int>> getdp(string str1, string str2) {
	int M = str1.length()-1;

	vector<vector<int>> dp(str1.length(), vector<int>(str2.length(), 0));

	dp[0][0] = str1[0] == str2[0] ? 1 : 0;

	// the first column
	for (int i = 1; i < str1.length(); ++i) {
		if (str1[i] == str2[0])
			dp[i][0] = 1;
	}

	// the first row
	for (int j = 1; j < str2.length(); ++j) {
		if (str2[j] == str1[0]) 
			dp[0][j] = 1;
	}

	// int maxLen = 0;
	// int index = 0;
	for (int i = 1; i < str1.length(); ++i) {
		for (int j = 1; j < str2.length(); ++j) {
			if (str1[i] == str2[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				// if (dp[i][j] > maxLen) {
				// 	maxLen = dp[i][j];
				// 	index = i;
				// }			
			}
		}
	}
	return dp;
}

string lcst1(string str1, string str2) {
	if (str1.length() == 0 || str2.length() == 0)
		return "";

	vector<vector<int>> dp = getdp(str1, str2);
	int end = 0;
	int maxLen = 0;
	for (int i = 0; i < str1.length(); ++i) {
		for (int j = 0; j < str2.length(); ++j) {
			if (dp[i][j] > maxLen) {
				end = i;	// 对str1而言的
				maxLen = dp[i][j];
			}
		}
	}

	return str1.substr(end-maxLen+1, end+1);
}

// 我们可以发现在求解dp的过程中，其实每一个值之和左上角的值有关系，所以可以把空间优化成O(1)
string lcst2(string str1, string str2) {
	if (str1.length() == 0 || str2.length() == 0)
		return "";

	int row = 0;
	int col = str2.length()-1;
	int maxLen = 0;
	int end_index = 0;	// 相对于str1的
	while (row < str1.length()) {
		int i = row;
		int j = col;
		int len = 0;
		while (i < str1.length() && j < str2.length()) {
			if (str1[i] == str2[j]) {
				++len;
			} else {
				len = 0;
			}

			if (len > maxLen) {
				maxLen = len;
				end_index = i;
			}
			++i;
			++j;
		}

		if (col > 0) {
			--col;
		} else {
			++row;
		}
	}

	return str1.substr(end-maxLen+1, end+1);
}