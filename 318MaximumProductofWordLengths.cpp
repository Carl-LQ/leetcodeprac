// 这道题我本来的想法是，先按照长度排个序，然后再用个set统计每个字符串里面的字母，然后用map把这个字符串和set联系起来。最终还是要O(N^2)来遍历找到最大的相乘的值。
// N方使我觉得我的方法很low，然后就去看了高赞回答，看来时间上很难优化了，也是N^2，但是他的方法很巧妙，直接用一个int来作为hashmap，其实也就是bitmap，在ext2文件系统等地方都有见到和用过的，只是自己思维还不够活跃没有想到，所以看懂以后实现了高赞回答的方法。
// 本质上其实也可以算是一道位运算的题吧。
class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.size() <= 1)
            return 0;
        
        vector<int> hm(words.size(), 0);
        
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].length(); ++j) {
                hm[i] |= (1 << words[i][j]-'a');
            }
        }
        
        size_t res = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i+1; j < words.size(); ++j) {
                if ((hm[i]&hm[j]) == 0) {
                    res = max(res, words[i].length()*words[j].length());
                }
            }
        }
        
        return res;
    }
};