// brute force, 以start开始的回文有多少个
int f(string s, int start) {
	if (start == s.length()-1) {
		return 1;
	}

}
// - - 写不出来，godness



int countSubstrings(string s) {
	int res = 0;
	vector<vector<bool> > dp(s.length(), vector<bool>(s.length()));
	for (int i = s.length()-1; i >= 0; --i) {	// 以i作为开头
		for (int j = i; j < s.length(); ++j) {	// 以j作为结尾
			dp[i][j] = s[i] == s[j] && (j - i < 3 || dp[i+1][j-1]);
			res += dp[i][j];
		}
	}
	return res;
}

// 这个快好多诶，主要是上面那个每次都要便利到，O(N^2)，下面这个如果一旦向左右扩不开了就停止了，最差情况下才是O(N^2)
int countSubstrings(string s) {
	int count = 0;
	for (int i = 0; i < s.length(); ++i) {
		int left = i;
		int right = i;
		while (left >= 0 && right < s.length() && s[left] == s[right]) {
			++count;
			--left;
			++right;
		}

		left = i;
		right = i+1;
		while (left >= 0 && right < s.length() && s[left] == s[right]) {
			++count;
			--left;
			++right;
		}
	}
	return count;
}