//Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/ 
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
    int minDepth(TreeNode* root) {
        if( !root ) return 0;
        if( root->left && root->right ){
            int left = minDepth(root->left)+1;
            int right = minDepth(root->right)+1;
            return min(left, right);
        }else if( root->left ){
            int left = minDepth(root->left)+1;
            return left;
        }else{
            int right = minDepth(root->right)+1;
            return right;
        }
        
        return 0;
        
    }
};