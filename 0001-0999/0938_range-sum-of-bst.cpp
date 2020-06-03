//Link: https://leetcode.com/problems/range-sum-of-bst/ 
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if( !root )return 0;
        int sum = (root->val >= L && root->val <=R) ? root->val : 0;
        sum += rangeSumBST(root->left, L, R);
        sum += rangeSumBST(root->right, L, R);
        return sum;
    }
};