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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || n == 0)
            return head;
        
        ListNode* cur = head;
        while(cur) {
            n--;
            cur = cur->next;
        }
        
        if (n == 0) {
            cur = head;
            head = head->next;
            delete cur;
        } else if (n < 0){
            cur = head;
            while (++n != 0) {
                cur = cur->next;
            }
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
        return head;
    }
};


// 上面那个方法是我看过左神的书写出来的，follow up是说如何一遍过，大部分高赞回答都是类似下面这样的，先让快指针走n+1步，然后慢指针再出发，快指针走到尾的时候慢指针恰好是要删除的倒数第n个的前一个。
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(n--) {
            fast = fast->next;
        }
        if (!fast) {    // 需要删除的是头节点
            head = head->next;
            delete slow;
            return head;
        }
        
        // 否则，还要移动一位，因为要让slow指向删除的节点的前一个当fast走到尾的时候
        fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = slow->next->next;
        delete fast;
        return head;
    }
};