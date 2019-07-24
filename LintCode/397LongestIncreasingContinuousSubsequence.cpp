class Solution {
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        // write your code here
        if (A.size() < 2)
            return A.size();
            
        int res = 1;
        int index = 1;
        int len_up = 1;
        int len_down = 1;
        while (index < A.size()) {
            if (A[index-1] < A[index]) {
                ++len_up;
                res = max(res, len_up);
                len_down = 1;
            } else if (A[index-1] > A[index]){
                ++len_down;
                res = max(res, len_down);
                len_up = 1;
            } else {
                res = max(len_down, max(res, len_up));
                len_up = 1;
                len_down = 1;
            }
            ++index;
        }
        
        return res;
    }
};