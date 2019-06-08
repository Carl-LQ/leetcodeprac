/*
    Remove Duplicates from Sorted List II.
    Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
*/

// Non-recursive version
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        
        ListNode* pre = fakeHead;
        ListNode* cur = head;
        
        while (cur) {
            while (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
            }
            if (pre->next == cur) {     // current node is unique
                pre = pre->next;
            } else {
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        
        return fakeHead->next;
    }
};

// Recursive version
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        int val = head->val;
        ListNode* cur = head->next;
        
        if (cur->val != val) {      // whether the linkedlist starts with duplicated nodes
            head->next = deleteDuplicates(cur);
            return head;
        } else {
            while (cur && cur->val == val) {
                cur = cur->next;
            }
            return deleteDuplicates(cur);
        }
    }
};