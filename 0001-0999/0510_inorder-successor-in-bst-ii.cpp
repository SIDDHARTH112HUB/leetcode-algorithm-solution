//Link: https://leetcode.com/problems/inorder-successor-in-bst-ii/ 
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    bool isFind = false;
    Node* ans = NULL;
    Node* inorderSuccessor(Node* node) {
        auto target = node;
        while(node->parent)
            node = node->parent;
        dfs(node, target);
        return ans;
    }
    
    void dfs(Node* root, Node* target) {
        if(!root) return;
        dfs(root->left, target);
        if(isFind && !ans) {
            ans = root;
            return;
        }
        if(root == target) {
            isFind = true;
        }
        dfs(root->right, target);
    }
};