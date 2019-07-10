// 直接用系统函数pow的话速度会慢很多，因为pow的参数是double类型，浮点型的乘法比整型的慢多了。想起来之前编程之美看过的用位运算求n的m次方的方法，大概凭理解和记忆写了一个方法，速度果然快了很多。
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        
        int m = n % 3;
        if (m == 0) {
            return getPow(3, n/3);
        } else if (m == 1) {
            return getPow(3, n/3-1) * 4;
        } else {
            return getPow(3, n/3) * 2;
        }
    }
    
    // bit operation to get the result: n to the power of m
    int getPow(int n, int m) {
        long temp = n;  // 这里是long或者long long类型最好了，不然48就已经会overflow了。
        int res = 1;
        while (m) {
            if (m & 1 == 1) {
                res *= temp;
            }
            m = m >> 1;
            temp *= temp;
        }
        return res;
    }
};