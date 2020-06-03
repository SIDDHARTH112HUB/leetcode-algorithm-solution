//Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/ 
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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
    int solve(TreeNode* root, int &res){
        if( !root ) return 0;
        int l = max(solve(root->left, res), 0);
        int r = max(solve(root->right, res), 0);
        res = max( res, l+r+root->val);
        return max(l, r)+root->val;
    }
};