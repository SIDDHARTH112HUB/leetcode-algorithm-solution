//Link: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/ 
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
    int val = 0;
    TreeNode* bstToGst(TreeNode* root) {
        //solve(root, val);
        //return root;
        if(!root) return NULL;
        bstToGst(root->right);
        val = root->val += val;
        bstToGst(root->left);
        return root;
    }
    
    void solve(TreeNode* root, int &val) {
        if(!root) return;
        solve(root->right, val);
        val = root->val += val;
        solve(root->left, val);
    }
};