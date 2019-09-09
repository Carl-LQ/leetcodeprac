/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node* next_level = root;
        while (next_level) {
            Node* cur = next_level;
            next_level = NULL;
            while (cur) {
                Node* next = cur->next;
                if (cur->left) {
                    setNextLevelPtr(next_level, cur->left);
                    if (cur->right) {
                        cur->left->next = cur->right;
                    } else if (next) {
                        findNextwithChild(next);
                        if (!next) {
                            break;
                        }
                        if (next->left) {
                            cur->left->next = next->left;
                        } else if (next->right) {
                            cur->left->next = next->right;
                        }
                    }
                }
            
                if (cur->right) {
                    setNextLevelPtr(next_level, cur->right);
                    if (next) {
                        findNextwithChild(next);
                        if (!next) {
                            break;
                        }
                        
                        if (next->left) {
                            cur->right->next = next->left;
                        } else if (next->right) {
                            cur->right->next = next->right;
                        }
                    }
                }
                
                cur = next;
            }
        }
        return root;
    }

private:
    void findNextwithChild(Node* &next) {
        while (next && !next->left && !next->right) {
            next = next->next;
        }
    }
    
    void setNextLevelPtr(Node* &next_level, Node* &ptr) {
        next_level = next_level == NULL ? ptr : next_level;
    }
};