//Link: https://leetcode.com/problems/symmetric-tree/ 
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
    bool isSymmetric(TreeNode* root) {
        if( !root ) return true;
        return sysmmetric(root->left, root->right);
    }
    
    bool sysmmetric(TreeNode* left, TreeNode* right){
        if( left && right ){
            if( left->val == right->val ){
                bool res = sysmmetric(left->left, right->right);
                if( !res )
                    return res;
                res = sysmmetric(left->right, right->left);
                return res;
            }
            return false;
        }
        return left == right;
    }
};