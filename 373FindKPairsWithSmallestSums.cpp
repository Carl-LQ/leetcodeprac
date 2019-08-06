// 这个问题的本质其实就是merge k sorted list，使用最小堆，堆里按照总和最小的存，然后关键是怎么存能够使效率高点，参考了高赞答案第一个
class Solution {
public:
    struct info{
        int num1;
        int num2;
        int num2_index;
        info(int n1, int n2, int n2_i) : num1(n1), num2(n2), num2_index(n2_i) {}
    };
    struct cmp{
        bool operator() (const info* i1, const info* i2) const {    // key point
            return i1->num1+i1->num2 > i2->num1+i2->num2;
        }  
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (k <= 0 || nums1.size() == 0 || nums2.size() == 0)
            return res;
        
        priority_queue<info*, vector<info*>, cmp> pq;   // array <nums1, nums2, nums2.cur_index>
        for (int i = 0; i < nums1.size() && i < k; ++i) {
            pq.push(new info(nums1[i], nums2[0], 0));
        }
        info* t = NULL;
        while (k-- > 0 && !pq.empty()) {
            t = pq.top();
            pq.pop();
            res.push_back({t->num1, t->num2});
            if (t->num2_index == nums2.size()-1)     // nums1[t[0]]和nums2的搭配已经全部计算过了，没了
                continue;
            pq.push(new info(t->num1, nums2[t->num2_index+1], t->num2_index+1));
        }
        
        return res;
    }
};