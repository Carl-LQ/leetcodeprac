// 比较经典的二分，但是抠边界还是挺细的
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid = 0;
        while (left <= right) {
            mid = left + (right-left >> 1);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                if (nums[mid] <= nums[right] && target > nums[right]) { //这里抠了半天要注意的细节，用right来进行对比，不要用left，因为每次计算的话，由于int/2是取floor，结果会在中间或者偏左边，在两个数的时候，mid=left，所以我们要用right来进行判断
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] > nums[right] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};