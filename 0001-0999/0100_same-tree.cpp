//Link: https://leetcode.com/problems/same-tree/ 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if( (p == NULL && q!=NULL )|| (p != NULL && q == NULL)) return false;
        if( p == q ) return true;
        bool res = false;
        if( p->val == q->val)
        {
            if( p->left != NULL && q->left != NULL )
            {
                res =  isSameTree( p->left, q->left);
            }
            else if ( p->left == NULL && q->left == NULL)
            {
                res = true;
            }
            else
                return false;
            if( res ==  false ) return false;
            
            if( p->right != NULL && q->right != NULL )
            {
                res =  isSameTree( p->right, q->right);
            }
            else if ( p->right == NULL && q->right == NULL)
            {
                res = true;
            }
            else
                return false;
            if( res ==  false ) return false;
            
        }
        return res;
    }
};