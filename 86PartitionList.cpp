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
    ListNode* partition(ListNode* head, int x) {
        ListNode* p1Head = new ListNode(0);
        ListNode* p2Head = new ListNode(0);
        ListNode* p1 = p1Head;
        ListNode* p2 = p2Head;
        
        while (head) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            } else {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p2->next = NULL;
        p1->next = p2Head->next;
        return p1Head->next;
    }
};