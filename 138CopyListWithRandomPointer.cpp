// 这道题也是左神讲过的，比较简单，就不用hashmap的那个方法实现了，之间空间复杂度O(1)一步到位~!
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;
        
        Node* cur = head;
        Node* curCopy = NULL;
        Node* next = NULL;
        while (cur) {
            next = cur->next;
            curCopy = new Node(cur->val);
            cur->next = curCopy;
            curCopy->next = next;
            cur = next;
        }
        
        cur = head;
        // set rand
        while (cur) {
            next = cur->next->next;
            curCopy = cur->next;
            curCopy->random = cur->random ? cur->random->next : NULL;
            cur = next;
        }
    
        
        cur = head;
        Node* newHead = head->next;
        // split
        while(cur) {
            next = cur->next->next;
            curCopy = cur->next;
            curCopy->next = next ? next->next : NULL;
            cur->next = next;
            cur = next;
        }
        return newHead;
    }
};