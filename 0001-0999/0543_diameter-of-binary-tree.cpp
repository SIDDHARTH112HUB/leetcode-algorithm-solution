//Link: https://leetcode.com/problems/diameter-of-binary-tree/ 
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        h(root);
        return ans - 1;
    }
    
    int h(TreeNode* root) {
        if(!root) return 0;
        int l = h(root->left);
        int r = h(root->right);
        int maxlr = max(l + 1, r + 1);
        ans = max(max(ans, maxlr), l + r + 1);
        return maxlr;
    }
};