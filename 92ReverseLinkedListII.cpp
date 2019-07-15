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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head)
            return NULL;
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode* preStart = NULL;
        ListNode* start = NULL;
        ListNode* end = NULL;
        ListNode* pre = NULL;
        ListNode* next = NULL;
        int i = 0;
        while (i < m-2 && head) {
            head = head->next;
            ++i;
        }
        preStart = m == 1 ? fakeHead : head;
        start = preStart->next;
        while (i++ < n && head) {
            head = head->next;
        }
        pre = head;
        end = head;
        while (start != end) {
            next = start->next;
            start->next = pre;
            pre = start;
            start = next;
        }
        preStart->next = pre;
        return fakeHead->next;
    }
};


//更简洁的方法, 反正我是想不出来这样移动- -
class Solution {
public:
   ListNode* reverseBetween(ListNode* head, int m, int n) {
       ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
       dummy -> next = head;
       for (int i = 0; i < m - 1; i++) {
           pre = pre -> next;
       }
       cur = pre -> next;
       for (int i = 0; i < n - m; i++) {
           ListNode* temp = pre -> next;
           pre -> next = cur -> next;
           cur -> next = cur -> next -> next;
           pre -> next -> next = temp;
       }
       return dummy -> next;
   }
};