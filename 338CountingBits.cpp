// 这道题没有写出很好的暴力递归，是直接找到了规律写的，下面是我的答案：
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        if (num == 0)
            return res;
        
        res[1] = 1;
        if (num == 1)
            return res;
        
        
        for (int i = 2; i <= num; ++i) {
            int bigestPowerOfTwo = findBigestNum(i);
            res[i] = res[bigestPowerOfTwo] + res[i-bigestPowerOfTwo] + (bigestPowerOfTwo == i);
        }
        
        return res;   
    }
    
    // 此函数是为了找不大于n的2的幂的整数
    int findBigestNum(int n) {
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        return (n+1) >> 1;
    }
};


// brute force
// vector<int> f(int num) {
//     vector<int> res;
//     if (num == 0) {
//         res.push_back(0);
//         return res;
//     }
    
//     res = f(num-1);
//     int bits = 0;
//     // get bits of num
//     while (num) {
//         if(num & 1) 
//             ++bits;
//         num >>= 1;
//     }
//     res.push_back(bits);
//     return res;
// }


/** 
    这是高赞回答：太恐怖了这思维，其实就是根据奇偶变化的原因，i&(i-1)可以先去掉某个数i最低位的1，由于i&(i-1)在之前求过了，可以直接获得，然后最后再加回一个1
    i&(i-1) drops the lowest set bit. For example: i = 14, its binary representation is 1110, so i-1 is 1101, i&(i-1) = 1100, the number of "1" in its binary representation decrease one, so ret[i] = ret[i&(i-1)] + 1. (Sorry, my English is so poor and I have tried my best to make it clearly, I hope you can understand my explanation)
*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};