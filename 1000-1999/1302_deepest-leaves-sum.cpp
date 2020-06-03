//Link: https://leetcode.com/problems/deepest-leaves-sum/ 
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
            map<int, int> m;
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;

        h(root, 0);
        return m.rbegin()->second;
    }
    void h(TreeNode* root, int d) {
        if(!root) return;
        m[d] += root->val;
        h(root->left, d+ 1);
        h(root->right, d + 1);
    }
};