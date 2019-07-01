class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = 1;
        while ((1<<level) - 1 < label) {
            ++level;
        }
        int i = 0;
        int cur = level;
        vector<int> index(level+1, 1);
        i = level & 1 ? label - (1 <<level-1) + 1 : (1 << level) - label;
        
        while (cur >= 1) {
            index[cur] = cur & 1 ? (1 << cur-1) + i - 1 : (1 << cur) - i;
            i = (i + 1) / 2;
            --cur;
        }
        vector<int> res(index.begin()+1, index.end());
        return res;
    }
};