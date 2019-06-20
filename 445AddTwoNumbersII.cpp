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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* old = NULL;
        ListNode* cur = NULL;
        stack<int> st1, st2;
        while (l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        
        while (l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        int n1 = 0;
        int n2 = 0;
        int sum = 0;
        while (!st1.empty() || !st2.empty() || carry) {
            if (!st1.empty()) {
                n1 = st1.top();
                st1.pop();
            } else {
                n1 = 0;
            }
            
            if (!st2.empty()) {
                n2 = st2.top();
                st2.pop();
            } else {
                n2 = 0;
            }
            sum = n1 + n2 + carry;
            carry = sum / 10;
            sum %= 10;
            cur = new ListNode(sum);
            cur->next = old;
            old = cur;
        }
        
        return cur;
    }
};