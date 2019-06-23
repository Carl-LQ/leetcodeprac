/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res(k);
        int count = 0;
        ListNode* cur = root;
        while (cur) {
            cur = cur->next;
            ++count;
        }
        int numInGroup = count / k;
        int extras = count % k;
        
        cur = root;
        for (int i = 0; i < k && cur; ++i) {
            res[i] = cur;
            for (int j = 1; j < numInGroup + (i < extras); ++j) {   // Remember j starts from 1
                cur = cur->next;
            }
            ListNode* temp = cur->next;
            cur->next = NULL;
            cur = temp;
        }
        
        return res;
    }
};