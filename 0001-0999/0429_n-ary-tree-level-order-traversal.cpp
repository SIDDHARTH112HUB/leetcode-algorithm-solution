//Link: https://leetcode.com/problems/n-ary-tree-level-order-traversal/ 
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
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while(q.size()) {
            int size = q.size();
            ans.push_back({});
            while(size-- > 0) {
                auto node = q.front();
                q.pop();
                ans.back().push_back(node->val);
                for(auto ch : node->children) {
                    q.push(ch);
                }
            }
            
        }
        return ans;
    }
};