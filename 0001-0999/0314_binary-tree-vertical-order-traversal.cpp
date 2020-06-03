//Link: https://leetcode.com/problems/binary-tree-vertical-order-traversal/ 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, vector<int > > m;
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<pair<int, TreeNode*> > q;
        q.push({0, root});
        while(q.size()) {
            auto p = q.front(); q.pop();
            auto d = p.first;
            auto node = p.second;
            m[d].push_back(node->val);
            if(node->left)
                q.push({d - 1, node->left});
            if(node->right)
                q.push({d + 1, node->right});
            
        }
        for(auto &it : m) {
            ans.push_back(it.second);
        }
        return ans;
    }
};