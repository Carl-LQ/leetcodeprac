/**
    这就是排列组合的问题，用位运算来实现。
    思路就是用一个正整数二进制表示第i个元素是取还是不取，如果这个正整数第i位是0就不取，是1就取。所以从0到(2^n)-1总共2^n个整数，正好对应集合的2^n个子集。
*/
class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());
        int s = 1 << nums.size();
        vector<vector<int>> res;
        for (unsigned int n = 0; n < s; ++n) {
            vector<int> elem1;
            unsigned int temp = n;
            unsigned int index = 0;
            while(temp != 0) {
                if (temp & 1 == 1) {
                    elem1.push_back(nums[index]);
                }
                ++index;
                temp = temp >> 1;
            }
            res.push_back(elem1);
        }
        return res;
    }
};