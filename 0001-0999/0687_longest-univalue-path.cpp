//Link: https://leetcode.com/problems/longest-univalue-path/ 
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
    int ans = 0;
    int longestUnivaluePath(TreeNode* root) {
        helper(root);
        return ans;
    }
    int helper(TreeNode* root) {
        if( !root ) return 0;
        int path = 0;
        int l = helper(root->left);
        int r = helper(root->right);
        if( root->left && root->left->val == root->val ){
            l++;
        }else l = 0;
        if( root->right && root->right->val == root->val )
            r++;
        else 
            r=0;
        ans = max(ans, l+r);
        return  max(l, r);
    }
};