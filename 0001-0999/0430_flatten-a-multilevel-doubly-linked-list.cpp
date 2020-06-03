//Link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/ 
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        return f(head).first;
    }
    
    pair<Node*, Node*> f(Node* head) {
        auto node = head;
        auto prev = node;
        while(node) {
            if(node->child) {
                auto p = f(node->child);
                node->child = NULL;
                auto h = p.first;
                auto t = p.second;
                auto next = node->next;
                node->next = h;
                h->prev = node;
                t->next = next;
                if(next)
                    next->prev = t;
                node = t;
            }
            prev = node;
            node = node->next;
        }
        return {head, prev};
    }
};