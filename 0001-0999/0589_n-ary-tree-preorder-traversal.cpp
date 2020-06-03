//Link: https://leetcode.com/problems/n-ary-tree-preorder-traversal/ 
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> ans;
    vector<int> preorder(Node* root) {
        f(root);
        return ans;
    }
    
    void f(Node* root) {
        if(!root) return;
        ans.push_back(root->val);
        for(auto ch : root->children)
            f(ch);
    }
};