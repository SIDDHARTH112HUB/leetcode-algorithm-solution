//Link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/ 
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
    int ans = INT_MAX;
    int getMinimumDifference(TreeNode* root, int mn = -10000000, int mx = 10000000) {
        if(!root) return 0;
        ans = min(ans, min(abs(root->val - mn), abs(root->val - mx)));
        getMinimumDifference(root->left, mn, root->val);
        getMinimumDifference(root->right, root->val, mx);
        return ans;
    }
};