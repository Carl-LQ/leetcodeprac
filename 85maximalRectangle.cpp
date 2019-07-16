// 调了大半天，看来自己对单调栈结构的理解还是不够，自己一个小优化卡死了自己。下面会在注释部分写写该注意的细节。下面这个是参考了左神的版本改的，其中栈顶的数值等于要加入的数值的部分是我优化卡住了，看了这个版本才理解为什么。
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        stack<int> minStack; 	// 存index
        int res = 0;
        vector<int> heights(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                heights[j] = matrix[i][j] == '1' ? heights[j]+1 : 0;
            }

            for (int j = 0; j < matrix[0].size(); ++j) {
                while (!minStack.empty() && heights[j] <= heights[minStack.top()]) {    // 当前栈如果不空且栈顶元素TOP（index，还要利用原数组找实际的值）小于或等于待加入的元素X，那么就一直弹出。这里等于的时候，虽然面积没有被正确计算，但由于两值相等，两者共享同一块矩形面积，所以不影响。也正是因为这一点我想到了一个优化，一开始想着可以直接不压入X的，反正两者面积相同，遇到了某些testcase过不了才发现应该是不要TOP，因为X能够正确地给出他后面的元素的左边界。现在想想也确实是，反正最省事的左神的方法都是直接弹出来，也就是TOP位置的面积计算不一定是正确的，我们用的是X的计算的面积。
                    // 被迫出来了
                    int height = heights[minStack.top()];
                    minStack.pop();   
                    int left = minStack.empty() ? -1 : minStack.top();
                    res = max(res, height * (j-1-left));
                }
                
                minStack.push(j);
            }

            while (!minStack.empty()) {
                int height = heights[minStack.top()];
                minStack.pop();
                int left = minStack.empty() ? -1 : minStack.top();
                res = max(res, height * (heights.size()-1-left));
            }

        }
        return res;
    }
};




// 所以有了下面这版我改改的代码，其实效率相差不大：
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        stack<int> minStack;    // 存index
        int res = 0;
        vector<int> heights(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                heights[j] = matrix[i][j] == '1' ? heights[j]+1 : 0;
            }

            for (int j = 0; j < matrix[0].size(); ++j) {
                while (!minStack.empty() && heights[j] < heights[minStack.top()]) {
                    // 被迫出来了
                    int height = heights[minStack.top()];
                    minStack.pop();
                    int right = j - 1;  // 这个变量可以省，但是加一个的话代码可阅读性会高一些，所以我没省
                    int left = minStack.empty() ? -1 : minStack.top();
                    res = max(res, height * (right-left));
                }
                while (!minStack.empty() && heights[j] == heights[minStack.top()]) {    // 相等的话，栈顶弹出可以不用计算，反正面积都不一定正确
                    minStack.pop();
                }
                
                minStack.push(j);
            }

            while (!minStack.empty()) {
                int height = heights[minStack.top()];
                minStack.pop();
                int right = heights.size()-1;
                int left = minStack.empty() ? -1 : minStack.top();
                res = max(res, height * (right-left));
            }

        }
        return res;
    }
};