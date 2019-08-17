// 腾讯二面的一道题，被搞懵了昨天，总是算搞懂了，看了高赞回答整理了俩小时，噗，继续加油！
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int secMinPrice = INT_MAX;  // 记录的是第一次卖出以后的价格以及第一次所赚的利润差，一直保持最小值，所以实际上可以认为是一次交易最大化利益打后的最低价格。
        int benefitOne = 0;
        int benefitTwo = 0;
        
        for (int p : prices) {
            minPrice = min(minPrice, p);                    // 永远只记录之前出现的最小的价格，表示第一次买入
            benefitOne = max(benefitOne, p-minPrice);       // 一次买卖能够带来的最大收益
            // 下面开始是关键，secMinPrice的写法，可以保证，即便benefitOne更新了，如果更新后没有得到更大的收益，依然记录的是之前的最大收益的买卖
            secMinPrice = min(secMinPrice, p-benefitOne);   // 第二次买入，此时手头的收益（可以为负）
            benefitTwo = max(benefitTwo, p-secMinPrice);    // 第二次卖出，两次的总收益
        }
        
        return benefitTwo;
    }
};