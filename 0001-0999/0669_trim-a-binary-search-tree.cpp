//Link: https://leetcode.com/problems/trim-a-binary-search-tree/ 
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        root = trim(root, L, R);
        return root;
    }
    TreeNode* trim(TreeNode* parent, int L, int R ){
        if( !parent )
            return NULL;
        if( parent->val < L ){
            parent->right = trim(parent->right, L, R );
            parent = parent->right;
        }
        else if( parent->val > R ){
            parent->left = trim(parent->left, L, R );
            parent = parent->left;
        }
        else{
            parent->left = trim(parent->left, L, R );
            parent->right = trim(parent->right, L, R );
        }
        return parent;
    }
};