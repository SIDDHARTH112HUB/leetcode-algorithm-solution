//Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/ 
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root ) return NULL;
        if( val < root->val ){
            if( root->left )
                insertIntoBST(root->left, val);
            else
                root->left = new TreeNode(val);
        }
        if( val > root->val){
            if( root->right )
                insertIntoBST(root->right, val);
            else
                root->right = new TreeNode(val);
        }
        return root;
    }
};