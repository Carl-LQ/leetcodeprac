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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || !head)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        int count = 0;
        while (head) {
            head = head->next;
            ++count;
        }
        k %= count;
        if (k == 0)
            return dummy->next;
        
        ListNode* pre = dummy;
        ListNode* start = NULL;
        int n = count - k;
        while (n > 0) {
            pre = pre->next;
            --n;
        }
        start = pre->next;
        pre->next = NULL;
        pre = start;
        
        while (start->next) {
            start = start->next;
        }

        start->next = dummy->next;
        dummy->next = pre;
        return dummy->next;
    }
};