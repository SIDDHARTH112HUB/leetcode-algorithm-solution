//Link: https://leetcode.com/problems/binary-tree-tilt/ 
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
    int helper(TreeNode* root, int &ans ){
        if( !root )
            return 0;
        int l = helper(root->left, ans);
        if( root->left )
            l += root->left->val;
        int r = helper(root->right, ans);
        if( root->right )
            r += root->right->val;
        ans += abs(l-r);
        return l+r;
    }
    int findTilt(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};