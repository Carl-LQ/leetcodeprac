// 是个人都能想出来的算法- -
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> um;
        while (n != 1) {
            if (um.count(n) == 1) {
                return false;
            } else {
                um.insert(n);
                n = SquareSum(n);
            }
        }
        return true;
    }
    
    int SquareSum(int n) {
        int sum = 0;
        int tmp = 0;
        while (n) {
            tmp = n % 10;
            sum += tmp*tmp;
            n /= 10;
        }
        return sum;
    }
};

// 用了弗洛伊德检测环的算法，空间只有O(1)，巧妙
class Solution {
public:
    bool isHappy(int n) {
        int fast{n}, slow{n};
        do {
            fast = SquareSum(SquareSum(fast));
            slow = SquareSum(slow);
        } while (fast != slow);
        return slow == 1;
    }
    
    int SquareSum(int n) {
        int sum = 0;
        int tmp = 0;
        while (n) {
            tmp = n % 10;
            sum += tmp*tmp;
            n /= 10;
        }
        return sum;
    }
};