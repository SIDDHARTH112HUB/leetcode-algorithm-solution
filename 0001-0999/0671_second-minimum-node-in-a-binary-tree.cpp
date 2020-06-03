//Link: https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/ 
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
    vector<int> n;
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        if(!root->left && !root->right ) return -1;
        int v = root->val;
        if(root->left->val > v)
            return root->left->val;
        if(root->right->val > v)
            return root->right->val;
        int l = findSecondMinimumValue(root->left);
        if( l >= 0) return l;
        int r = findSecondMinimumValue(root->right);
        if(r >= 0) return r;
        return -1;
    }
};