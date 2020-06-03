//Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/ 
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
    int kthSmallest(TreeNode* root, int &k) {
        if( !root ) return -1;
        
        int val = kthSmallest(root->left, k );
        if( k <= 0 ) return val;
        k--;
        if( k == 0 )
            return root->val;
        return kthSmallest(root->right, k);
    }
};