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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<int> st;
        while(head) {
            res.push_back(head->val);
            head = head->next;
        }
        int i = 0;
        int temp = 0;
        for (i = res.size() - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= res[i]) {
                st.pop();
            }
            temp = res[i];
            res[i] = st.empty() ? 0 : st.top();
            st.push(temp);
        }
        return res;
    }
};