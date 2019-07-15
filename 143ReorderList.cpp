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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return ;    
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        fast = slow->next;
        slow->next = NULL;
        slow = reverseLinkedList(fast);
        
        // 这是一开始的版本，循环不够简洁导致要判断末尾的情况，换成下面那种就好多了
        // while (head->next && slow->next) {
        //     ListNode* temp = head->next;
        //     head->next = slow;
        //     head = temp;
        //     temp = slow->next;
        //     slow->next = head;
        //     slow = temp;
        // }
        // if (head->next) {
        //     slow->next = head->next;
        // }
        // head->next = slow;    
        
        // 参考了高赞回答的
        while (head) {
            ListNode* temp = head->next;
            head->next = slow;
            head = slow;
            slow = temp;
        }


    }
    
    ListNode* reverseLinkedList(ListNode* head) {
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