// 感觉是一道贪心，然后想到了之前遇到过的类似的题，想了一下可以用堆来进行做（或者是排序），主要就是写一个比较函数。整体不难，就是有一个特殊的情况就是全0的话就只返回一个0，还是考虑得不够周全呀。
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        priority_queue<string, vector<string>, function<bool(string, string)>> pq(cmp);
        bool allZero = true;
        for (int n : nums) {
            if (n)
                allZero = false;
            pq.push(to_string(n));
        }
        if (allZero)
            return "0";
        
        string res = "";
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        
        return res;
    }
private:
    static bool cmp(const string& str1, const string& str2) {
        return str1+str2 < str2+str1;
    }
};