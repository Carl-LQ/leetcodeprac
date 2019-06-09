/**
    Given a singly linked list, determine if it is a palindrome.
    Achieving in O(n) time and O(1) space;
    Using stack is easily to achieve in O(n) time and space. But this one only use several pointers.
*/


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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        
        ListNode* slow_pointer = head;
        ListNode* fast_pointer = head;
        
        while (fast_pointer) {
            if (!fast_pointer->next || !fast_pointer->next->next) {
                break;
            }
            slow_pointer = slow_pointer->next;
            fast_pointer = fast_pointer->next->next;
        }
        
        // reverse it
        ListNode* pre = NULL;
        ListNode* next = NULL;
        
        while (slow_pointer) {
            next = slow_pointer->next;
            slow_pointer->next = pre;
            pre = slow_pointer;
            slow_pointer = next;
        }
        
        fast_pointer = pre; // for recovering
        
        slow_pointer = head;
        while(slow_pointer && pre) {
            if (slow_pointer->val != pre->val)
                return false;
            slow_pointer = slow_pointer->next;
            pre = pre->next;
        }
        
        // recover it
        pre = NULL;
        while (fast_pointer) {
            next = fast_pointer->next;
            fast_pointer = pre;
            pre = fast_pointer;
            fast_pointer->next = next;
        }
        
        return true;
        
    }
};