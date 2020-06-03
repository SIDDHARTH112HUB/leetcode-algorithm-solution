//Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/ 
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( p->val > q->val ){
            TreeNode* t = p;
            p = q;
            q = t;
        }
        while( root ){
            if( root->val < p->val )
                root = root->right;
            else if( root->val > q->val )
                root = root->left;
            else
                return root;
        }
        return root;
    }
};