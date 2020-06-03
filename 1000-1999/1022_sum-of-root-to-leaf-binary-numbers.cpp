//Link: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/ 
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
    int ans = 0;
    int sumRootToLeaf(TreeNode* root, int num = 0) {
        if(!root) return 0;
        num = (num << 1) + root->val;
        sumRootToLeaf(root->left, num);
        sumRootToLeaf(root->right, num);
        if(!root->left && !root->right)
            ans += num;
        return ans;
    }
};