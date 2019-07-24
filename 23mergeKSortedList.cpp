/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 最简单的第一种，用堆，最小堆，每次之加入每个链表的其中头一个节点。
class Solution {
public:
    static bool cmp(ListNode* l1, ListNode* l2) {
        return l1->val > l2->val;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> pq(cmp);
        for(ListNode* node : lists) {
            if (node) 
                pq.push(node);
        }
        
        ListNode* head = NULL;
        ListNode* cur = NULL;
        ListNode* pre = NULL;
        while (!pq.empty()) {
            cur = pq.top();
            pq.pop();
            if (pre == NULL) {
                head = cur;
            } else {
                pre->next = cur;
            }
            pre = cur;
            if (cur->next) {
                pq.push(cur->next);
            }
        }
        return head;
    }
};


// 第二种方法是分治法，自顶向下的，时间复杂度也是O(NlogK)，N为总的节点数，K为链表个数
class Solution {
public:
    static bool cmp(ListNode* l1, ListNode* l2) {
        return l1->val > l2->val;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        
        return divideAndConqur(lists, 0, lists.size()-1);
    }
    
    ListNode* divideAndConqur(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        
        int mid = start + (end-start>>1);
        ListNode* l = divideAndConqur(lists, start, mid);
        ListNode* r = divideAndConqur(lists, mid+1, end);
        return mergeTwoSortedList(l, r);
    }
    
    ListNode* mergeTwoSortedList(ListNode* l, ListNode* r) {
        if (l == NULL) {
            return r;
        }
        if (r == NULL) {
            return l;
        }
        
        ListNode* head = NULL;
        ListNode* cur = NULL;
        ListNode* tail = NULL;
        while (l && r) {
            if (l->val < r->val) {
                cur = l;
                l = l->next;
            } else {
                cur = r;
                r = r->next;
            }
            
            if (!tail) {
                head = cur;
            } else {
                tail->next = cur;
            }
            tail = cur;
        }
        
        if (l) {
           tail->next = l; 
        } else {
            tail->next = r;
        }
    
        return head;
    }
    
};


// 最后一种，自底向上的方法，因为我们已经想出了分治的方法，我们可以逆过程自底向上推，时间复杂度一样是O(NlogK)
class Solution {
public:
    static bool cmp(ListNode* l1, ListNode* l2) {
        return l1->val > l2->val;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        
        while (lists.size() > 1) {
            vector<ListNode*> new_lists;
            for (int i = 0; i+1 < lists.size(); i += 2) {
                new_lists.push_back(mergeTwoSortedList(lists[i],lists[i+1]));
            }
            if (lists.size() & 1) {
                new_lists.push_back(lists[lists.size()-1]);
            }
            lists.swap(new_lists);
        }
        
        return lists[0];
    }
    
    ListNode* mergeTwoSortedList(ListNode* l, ListNode* r) {
        if (!l)
            return r;
        
        if (!r)
            return l;
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        ListNode* cur = NULL;
        while (l && r) {
            if (l->val < r->val) {
                cur = l;
                l = l->next;
            } else {
                cur = r;
                r = r->next;
            }
            
            if (tail == NULL) {
                head = cur;
            } else {
                tail->next = cur;
            }
            
            tail = cur;
        }
        
        tail->next = l ? l : r;
        return head;
    }
    
};