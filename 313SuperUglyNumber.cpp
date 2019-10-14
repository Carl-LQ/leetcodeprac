// 这是我的思路，根据之前的Ugly Number II进行了一些修改，想着数字一旦多起来的话，用小根堆来避免每次重复的计算，没想到效率好像很低- -
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n);
        dp[0] = 1;
        
        vector<int> idxs(primes.size(), 0);
        priority_queue<Info*, vector<Info*>, function<bool(const Info*,const Info*)>> pq(cmp);
        for (int i = 0; i < primes.size(); ++i) {
            pq.push(new Info(primes[i]*dp[idxs[i]], i));
        }
        
        for (int i = 1; i < n; ++i) {
            Info* info = pq.top();
            pq.pop();
            dp[i] = info->val;
            
            int index = info->idx;
            ++idxs[index];
            pq.push(new Info(primes[index]*dp[idxs[index]], index));
            
            info = pq.top();
            while (pq.top()->val == dp[i]) {
                pq.pop();
                index = info->idx;
                ++idxs[index];
                pq.push(new Info(primes[index]*dp[idxs[index]], index));
                info = pq.top();
            }
        }
        
        return dp[n-1];
    }
private:
    struct Info {
        int val;    // primes[idx] * dp[idxs[idx]]
        int idx;    // primes[idx]
        Info(int v=0, int i=0) : val(v), idx(i) {}
    };
    
    static bool cmp(const Info *i1, const Info *i2) {
        return i1->val > i2->val;
    }
};


// 然而，好像还没最简单暴力的方法快。。。
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n, INT_MAX);
        dp[0] = 1;
        
        vector<int> idxs(primes.size(), 0);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < primes.size(); ++j) {
                dp[i] = min(dp[i], primes[j]*dp[idxs[j]]);
            }
            
            for (int j = 0; j < primes.size(); ++j) {
                if (dp[i] == primes[j]*dp[idxs[j]]) {
                    ++idxs[j];
                }
            }
        }
        
        return dp[n-1];
    }
};

// 稍微再用空间换一下时间？这个是真的快
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n);
        dp[0] = 1;
        
        vector<int> idxs(primes.size(), 0);
        vector<int> val(primes.size(), 1);
        int next = 1;
        for (int i = 0; i < n; ++i) {
            dp[i] = next;

            next = INT_MAX;
            for (int j = 0; j < primes.size(); ++j) {
                if (dp[i] == val[j]) {
                    val[j] = primes[j] * dp[idxs[j]++];
                }
                next = min(next, val[j]);
            }
            
        }
        return dp[n-1];
    }
};