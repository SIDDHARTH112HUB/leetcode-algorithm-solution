//Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/ 
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
    unordered_map<int, int> m;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        if(m.count(k - root->val)) return true;
        m[root->val] = 1;
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};