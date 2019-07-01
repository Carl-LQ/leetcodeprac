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
    ListNode* sortList(ListNode* head) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* tail = head;
		int count = 0;
		while (tail) {
			++count;
			tail = tail->next;
		}

		ListNode* cur = NULL;
		ListNode* left = NULL;
		ListNode* right = NULL;
		for (int step = 1; step < count; step <<= 1) {
			tail = dummy;
			cur = dummy->next;

			while (cur) {
				left = cur;
				right = split(cur, step);
				cur = split(right, step);
				tail->next = merge(left, right);
				while (tail->next) {
					tail = tail->next;
				}
			}
		}

		return dummy->next;
    }

    // split the first step nodes as the first list, return the head of the second list
    ListNode* split(ListNode* head, int step) {
    	while (head && --step) {
    		head = head->next;
    	}

    	if (!head)
    		return NULL;

    	ListNode* next = head->next;
    	head->next = NULL;
    	return next;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
    	ListNode* dummy = new ListNode(0);
    	ListNode* cur = dummy;
    	while (l1 && l2) {
    		if (l1->val < l2->val) {
    			cur->next = l1;
    			l1 = l1->next;
    		} else {
    			cur->next = l2;
    			l2 = l2->next;
    		}
    		cur = cur->next;
    	}

    	if (l1) {
    		cur->next = l1;
    	}
    	if (l2) {
    		cur->next = l2;
    	}
    	return dummy->next;
    }
};