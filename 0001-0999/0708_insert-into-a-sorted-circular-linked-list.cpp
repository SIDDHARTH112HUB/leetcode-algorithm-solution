//Link: https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/ 
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        if(!head) {
            node->next = node;
            return node;
        }
        auto prev = head;
        auto next = head->next;
        while(next != head) {
            if(prev->val <= insertVal && next->val >= insertVal) {
                prev->next = node;
                node->next = next;
                return head;
            }
            if(prev->val > next->val && (insertVal > prev->val || insertVal< next->val)) {
                prev->next = node;
                node->next = next;
                return head;
            }
            prev = next;
            next = next->next;
        }
        prev->next = node;
        node->next = next;
        return head;
    }
};