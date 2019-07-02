#include <iostream>
#include <vector>

using namespace std;

/**
	其实严格来说这道题是贪心算法的归类，每次都贪最远能走到哪里。
	遍历整个数组，全局变量记录最远能到达的点，如果遍历到某个点的时候发现最远能到达的点还在他前面，那么就证明后续的点都无法到达。否则，遍历完整个数组都能到达的话，返回true。
*/
bool canJump(vector<int> &A) {
    // write your code here
    int farest = A[0];
    for (int i = 1; i < A.size(); ++i) {
        if (farest < i)
            return false;
        farest = max(farest, i+A[i]);
    }
    return true;
}


/** Brute force
	但是也可以练练dp的思维。这是自顶向下的递归写法。
*/
bool move(const vector<int>& arr, int start, int end) {
	if (start == end) {
		return true;
	} else if (start > end) {
		return false;
	} else {
		bool res = false;
		for (int i = 1; i <= arr[start] && start+i <= end; ++i) {
			res = res || move(arr, start+i, end);
		}
		return res;
	}
}

// Initial: start=0, end=arr.size()-1
bool move_dp(const vector<int>& arr, int start, int end) {
	vector<vector<bool> > dp(arr.size(), vector<bool>(arr.size(), false));
	for (int i = end; i >= start; --i) {
		dp[i][i] = true;
		for (int step = 1; i + step <= end; ++step) {
			if (step <= arr[i]) {
				dp[i][i + step] = true;
			} else {
				for (int j = 1; j <= arr[i] && i + j <= end; ++j) {
					dp[i][i + step] = dp[i][i + step] || dp[i + j][i + step];
				}
			}
		}
	}
	return dp[start][end];
}


// 上面那个想复杂了，其实可以把dp表当作一维表，反正我们只想知道能否从start跳到end，所以相当于我们只看上面那个二维表的第一行
bool move_dp2(const vector<int>& arr) {
	// start = 0, end = arr.size()-1
	vector<bool> can(arr.size(), false);
	can[0] = true;
	for (int end = 1; end < arr.size(); ++end) {	//以每一个位置作为终止位置来看，看是否能跳到这个位置
		can[end] = 0;
		for (int start = 0; start < end; ++start) {
			if (can[start] && start + arr[start] >= end) {	//能到达start位置，且start位置开始能到达end位置
				can[end] = true;
				break;
			}
		}
	}

	return can[arr.size()-1];
}

/** 基于dp2，还有一个优化，就是如果在某一个点不可到达了，那就直接返回false，因为这意味着最远能走到的距离，这个点以及他后续的点都无法到达了
	到这一步优化就已经很不错了，严格的O(N^2)
*/
bool move_dp3(const vector<int>& arr) {
	bool can = true;
	for (int end = 1; end < arr.size(); ++end) {
		can = false;
		for (int start = 0; start < end; ++start) {
			if (start + arr[start] >= end) {
				can = true;
				break;
			}
		}
		if (!can)
			return false;
	}
	return true;
}

