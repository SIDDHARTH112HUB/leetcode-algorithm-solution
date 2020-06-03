//Link: https://leetcode.com/problems/sum-of-left-leaves/ 
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
    int sumOfLeftLeaves(TreeNode* root, int deep= 0) {
        if( !root ) return 0;
        int ans = 0;
        ans += sumOfLeftLeaves(root->left, deep+1);
        ans += sumOfLeftLeaves(root->right, 0);
        if( !root->left && !root->right && deep > 0)
            ans += root->val;
        return ans;
    }
};