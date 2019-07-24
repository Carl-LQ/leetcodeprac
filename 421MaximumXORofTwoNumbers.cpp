class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        head = new TrieNode();
        int res = 0;
        addNum(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            res = max(res, maxXor(nums[i]));
            addNum(nums[i]);
        }
        return res;
    }
private:
    struct TrieNode{
        array<TrieNode*, 2> nexts;
        TrieNode() {
            nexts[0] = NULL;
            nexts[1] = NULL;
        }
    };
    
    TrieNode* head;
    
    void addNum(int n) {
        TrieNode* cur = head;
        for (int i = sizeof(int)*8-1; i >= 0; --i) {
            int path = (n >> i) & 1;
            if (!cur->nexts[path])
                cur->nexts[path] = new TrieNode();
            cur = cur->nexts[path];
        }
    }
    
    int maxXor(int n) {
        TrieNode* cur = head;
        int res = 0;
        for (int i = sizeof(int)*8-1; i >= 0; --i) {
            int path = (n >> i) & 1;
            int best = i == sizeof(int)*8-1 ? path : path^1;
            best = cur->nexts[best] ? best : best^1;
            res |= ((path ^ best) << i);
            cur = cur->nexts[best];
        }
        return res;
    }
};