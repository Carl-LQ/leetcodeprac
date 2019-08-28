class Solution {
public:
    string getPermutation(int n, int k) {
        string res(n, '0');
        vector<int> count(n+1, 0);    // 0: not used
        vector<int> A(n+1, 1);
        int i = 1;
        for(i = 2; i <= n; ++i) {
            A[i] = i*A[i-1];
        }
        
        int cur_n = 0, j = 0, mod = 0;
        for (i = 1; n-i >= 1; ++i) {
            mod = k % A[n-i];
            cur_n = k / A[n-i] + (mod > 0);
            k = mod == 0 ? A[n-i] : mod;
            for (j = 1; j <= n; ++j) {
                if (count[j] == 1) {
                    continue;
                }
                
                if (--cur_n == 0) {
                    res[i-1] = j+'0';
                    count[j] = 1;
                    break;
                }
            }
        }
        
        j = 1;
        while (j <= n && count[j] == 1) ++j;
        res[n-1] = j+'0';
        
        return res;
    }
};