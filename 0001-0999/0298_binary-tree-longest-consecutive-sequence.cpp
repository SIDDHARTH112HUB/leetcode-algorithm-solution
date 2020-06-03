//Link: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/ 
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
    int ans = 0;
    int longestConsecutive(TreeNode* root) {
        dfs(root, -1000000);
        return ans;
    }
    
    pair<int, int> dfs(TreeNode* root, int p) {
        if(!root) return {1, 1};
        auto l = dfs(root->left, root->val);
        auto r = dfs(root->right, root->val);
        pair<int, int> res = {1, 1};
        if(p - root->val == 1) {
            res = {max(l.first, r.first) + 1,  1};
        }else if(root->val - p == 1) {
            res = {1, max(l.second, r.second) + 1};
        }
        ans = max(ans, res.second);
        return res;
    }
};