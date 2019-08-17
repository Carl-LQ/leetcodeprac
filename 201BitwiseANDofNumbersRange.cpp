// 我的理解这道题就是让我们找m和n的最长公共前缀，因为一旦有一位不同了，后面肯定都是0，因为自此以后从n到m递增一定会经历每一位从0变1的过程。
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        unsigned int mask = 1 << 30;
        for (int i = 30; i >= 0; --i) {
            if (n & mask) {
                break;
            }
            mask >>= 1;
        }
        
        unsigned int mask2 = mask;
        while (mask2) {
            if ((mask2&m) == (mask2&n)) {
                mask |= (mask2&m);
                mask2 >>= 1;
            } else {
                mask &= (~mask2);
                break;
            }
        }
        return mask;
    }
};