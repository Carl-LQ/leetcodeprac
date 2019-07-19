// 算是比较简单的，两边往中间夹，谁矮移动谁，因为往里面缩，宽度减少了，那么肯定越高越好，高的不要动，永远保持移动较矮的一方就不会错过正确答案。
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxArea = 0;
        while (left < right) {
            maxArea = max(maxArea, min(height[left], height[right]) * (right-left));
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return maxArea;
    }
};

// 下面是参考了高赞答案的，有道理，虽然也是移动，但是不是移动每一个我都要计算，我们可以忽略中间那些比高度还要矮的（那些不可能是答案），所以理论上能省去一些计算步骤，尽管在testcase上体现不太出来。
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxArea = 0;
        while (left < right) {
            int h = min(height[left], height[right]);
            maxArea = max(maxArea, h*(right-left));
            if (height[left] < height[right]) {
                while (left < right && height[++left] <= h);
            } else {
                while (left < right && height[--right] <= h);
            }
        }
        return maxArea;
    }
};