//Link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/ 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans = INT_MIN;
    int maxAncestorDiff(TreeNode* root, int mn = INT_MAX, int mx = INT_MIN) {
        if(!root) return INT_MIN;
        if(mn != INT_MAX) {
            int res = max(abs(root->val - mn), abs(root->val - mx));
            ans = max(ans, res);
        }
        maxAncestorDiff(root->left, min(mn, root->val), max(mx, root->val));
        maxAncestorDiff(root->right, min(mn, root->val), max(mx, root->val));
        return ans;
    }
};