/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return NULL;
        ListNode* cur = head;
        int len = 0;
        while (cur) {
            ++len;
            cur = cur->next;
        }
        
        vector<int> arr(len);
        len = 0;
        while (head) {
            arr[len++] = head->val;
            head = head->next;
        }
        return getTree(arr, 0, arr.size()-1);
    }

    TreeNode* getTree(vector<int> &arr, int start, int end) {
        if (start > end) {      // 这里是注意点1，start > end，而不是 start == end，因为递归的时候，是center-1了，不用大于号很有可能无法中止
            return NULL;
        }
        
        int center = start + (end - start >> 1);    // 注意点2，运算符的优先级比位移符高，切记
        TreeNode* root = new TreeNode(arr[center]);
        root->left = getTree(arr, start, center-1);
        root->right = getTree(arr, center+1, end);
        return root;
    }
};

// 参考了下高赞回复，也可以写成空间复杂度为O(1)的，就是时间上可能会变成O(NlogN)
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedList2BST(head, NULL);
    }

    TreeNode* sortedList2BST(ListNode* head, ListNode* tail) {
        if (head == tail)
            return NULL;
        if (head->next == tail)
            return new TreeNode(head->val);
        
        ListNode* mid = head;
        ListNode* fast = head;
        while (fast->next != tail && fast->next->next != tail) {
            fast = fast->next->next;
            mid = mid->next;
        }
        
        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedList2BST(head, mid);
        root->right = sortedList2BST(mid->next, tail);
        return root;
    }
};