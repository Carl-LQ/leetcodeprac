// 这是高赞回答，虽然感觉和自己写的用队列的层次遍历在时间上没太大区别，但人家空间是O(1)的，而且思路很巧妙，牛！（可是leetcode上的空间使用貌似和我的一样，不知道为什么，可能testcase都太小了。）
class Solution {
public:
    Node* connect(Node* root) {
        
        Node* level_start = root;
        while (level_start) {
            Node* cur = level_start;
            
            while (cur) {
                if (cur->left) {
                    cur->left->next = cur->right;
                }
                if (cur->right && cur->next) {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            
            level_start = level_start->left;
        }
        
        return root;
    }
};