//Link: https://leetcode.com/problems/delete-leaves-with-a-given-value/ 
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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        h(root, target);
        return root;
    }
    
    void h(TreeNode* &root, int t) {
        if(!root) return;
        h(root->left, t);
        h(root->right, t);
        if(!root->left && !root->right && root->val == t)
            root = NULL;
    }
};