class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int index = 0;  // count of non-positive numbers
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] > 0) {
                index = i;
                break;
            }
        }
        int res = 0;
        int i = 0;
        if (index > K) {
            for (i = 0; i < K; ++i) {
                res -= A[i];
            }
            for (; i < A.size(); ++i) {
                res += A[i];
            }
        } else {
            for (i = 0; i < index; ++i) {
                res -= A[i];
            }
            for (; i < A.size(); ++i) {
                res += A[i];
            }
            K = (K - index) & 1;
            if (K) {
                if (index > 0) {    // all positives
                    res -= abs(A[index]) > abs(A[index-1]) ? 2*abs(A[index-1]) : 2*abs(A[index]);
                } else {
                    res -= 2*A[index];
                }
            }
        }
        return res;
    }
};