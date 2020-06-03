//Link: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/ 
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
    int res = 0;
    int longestConsecutive(TreeNode* root) {
        dfs(root, root);
        return res;
    }
    
    pair<int, int> dfs(TreeNode* root, TreeNode* parent) {
        if(!root) return {0, 0};
        auto l = dfs(root->left, root);
        auto r = dfs(root->right, root);
        res = max(res, l.first + r.second + 1);
        res = max(res, l.second + r.first + 1);
        int inc = 0, dec = 0;
        if (root->val == parent->val + 1) {
            dec = max(l.second, r.second) + 1;
        } else if (root->val + 1 == parent->val) {
            inc = max(l.first, r.first) + 1;
        }
        return {inc, dec};
    }
};