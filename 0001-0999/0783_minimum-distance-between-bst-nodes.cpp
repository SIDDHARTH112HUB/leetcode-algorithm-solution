//Link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/ 
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
    int minDiffInBST(TreeNode* root) {
        if( root == NULL ) return 0;
        int lval = 1000000;
        int rval = 1000000;
        if( root->left ){
            lval = help(root->val, root->left);
            
            int res = minDiffInBST(root->left);
            if( res <lval && res > 0 )
                lval = res;
        }
        if( root->right ){
            rval = help(root->val, root->right);
            int res = minDiffInBST(root->right);
            if( res < rval && res > 0 )
                rval = res;
        }
        return rval < lval ? rval : lval;
        
    }
    
    int help(int val, TreeNode* root){
        if( val == root->val)
            return 1000000;
        int res = abs(root->val -val);
        if( root->left ){
            int lval = help(val, root->left);
            if( lval < res )
                res = lval;
            
        }
        if( root->right){
            int rval = help(val, root->right);
            if( rval < res)
                res = rval;
        }
        return res;
    }
};