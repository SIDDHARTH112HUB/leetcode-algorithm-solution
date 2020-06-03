//Link: https://leetcode.com/problems/house-robber-iii/ 
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
    unordered_map<TreeNode*, int> m;
    int rob(TreeNode* root) {
        if( m.count(root) ) return m[root];
        m[root] = root ? max(root->val + 
             (root->left ?  (rob(root->left->left) + rob(root->left->right) ) : 0 ) +
             (root->right? (rob(root->right->left) + rob(root->right->right) ) :0),
             rob(root->left) + rob(root->right)) : 0;
        return m[root];
    }
};

