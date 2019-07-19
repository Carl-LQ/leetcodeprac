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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k < 2)
            return head;
        
        ListNode* pre = NULL;
        ListNode* next = NULL;
        ListNode* cur = head;   // 实际上是记录组内的end的
        ListNode* start = NULL;
        int count = 1;
        while (cur) {
            next = cur->next;
            if (count == k) {
                start = pre == NULL ? head : pre->next;     // 注意，这两句不能交换了，交换的话，第一组的时候start的位置会出错
                head = pre == NULL ? cur : head;            // 遇到第一组的时候需要正确地设置头节点
                reverseList(pre, start, cur, next);
                pre = start;
                count = 0;
            }
            ++count;
            cur = next;
        }
        
        return head;
    }
    
    // reverse linked list
    void reverseList(ListNode* left, ListNode* start, ListNode* end, ListNode* right) {
        ListNode* pre = right;
        ListNode* next = NULL;
        ListNode* cur = start;
        while (cur != right) {      // 这里要注意是不能到他的下一个，也就是不能跨到下一组，而不是不能到NULL，否则会成环报错。
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        if (left) { // 非空，也就是非第一组，不用特殊处理
            left->next = end;
        }
    }
};