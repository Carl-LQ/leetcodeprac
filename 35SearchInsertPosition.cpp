// 线性扫描肯定慢，比较简单的二分查找的题，注意就是边界的情况
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) { // 这里注意是<=，因为返回的其实是第一个>或者= target的下标
            int center = left + (right-left >> 1);
            if (nums[center] < target) {
                left = center+1;
            } else {
                if (nums[center] == target && ((center > 1 && nums[center-1] != target) || center == 0)) // 如果加上这个判断条件的话就能处理有duplicate的情况，不然就不能
                    return center;
                else
                    right = center-1;
            }
        }
        return left;
    }
};