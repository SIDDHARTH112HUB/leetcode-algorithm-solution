//Link: https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/ 
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        
        if(!root->left && !root->right) {
            root->left = root;
            root->right = root;
            return root;
        }
        auto l = treeToDoublyList(root->left);
        auto r = treeToDoublyList(root->right);
        auto head = root;
        
        root->left = NULL;
        root->right = NULL;
        if(l) {
            head = l;
            auto lhead = l;
            auto ltail = l->left;
            lhead->left = root;
            ltail->right = root;
            root->left = ltail;
            root->right = lhead;
        }
        if(r) {
            auto rhead = r;
            auto rtail = r->left;
            rhead->left = root;
            rtail->right = head;
            if(!root->left) 
                head->left = rtail;
            head->left = rtail;
            root->right = rhead;
        }
        return head;
    }
};