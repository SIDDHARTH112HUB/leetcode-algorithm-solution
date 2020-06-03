//Link: https://leetcode.com/problems/balanced-binary-tree/ 
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
    int Height(TreeNode* node, bool &blance)
    {
        if( node == NULL ) return 0;
        int lh = Height(node->left, blance);
        int rh =  Height(node->right, blance);
        if( abs(lh-rh) >1 ) blance = false;
        return ((lh>rh?lh:rh)+1);
    }
    bool isBalanced(TreeNode *root) {
        if ( root == NULL ) return true;
        bool blance = true;
        int lh = Height(root->left, blance);
        int rh = Height(root->right, blance);
        if( !blance ) return blance;
        return abs(lh-rh)<=1;
    }
};