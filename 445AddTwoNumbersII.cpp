/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// version 1: reverse list
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* reversedList1 = reverseList(l1);
        ListNode* reversedList2 = reverseList(l2);
        ListNode* newHead = new ListNode(0);
        ListNode* cur = newHead;
        int carry = 0;
        int sum = 0;
        int n1 = 0;
        int n2 = 0;
        while (reversedList1 || reversedList2 || carry) {
            if (reversedList1) {
                n1 = reversedList1->val;
                reversedList1 = reversedList1->next;
            } else {
                n1 = 0;
            }
            
            if (reversedList2) {
                n2 = reversedList2->val;
                reversedList2 = reversedList2->next;
            } else {
                n2 = 0;
            }
            sum = carry + n1 + n2;
            carry = sum / 10;
            sum %= 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
        }
        
        newHead = reverseList(newHead->next);
        return newHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while (head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};


// version 2： use stack
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        stack<int> st1;
        stack<int> st2;
        int carry = 0;
        int sum = 0;
        int n1 = 0;
        int n2 = 0;
        while (l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }
        
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
            ListNode* newNode = new ListNode(sum);
            newNode->next = head->next;
            head->next = newNode;
        }
        
        return head->next;
    }
};