//Link: https://leetcode.com/problems/two-sum-bsts/ 
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
    unordered_set<int> m;
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(!root1 || !root2) return false;
        helper(root1);
        return helper2(root2, target);
    }
    void helper(TreeNode* root) {
        if(!root) return;
        m.insert(root->val);
        helper(root->left);
        helper(root->right);
    }
    bool helper2(TreeNode* root, int target) {
        if(!root) return false;
        if(m.count(target - root->val)) return true;
        if(helper2(root->left, target)) return true;
        if(helper2(root->right, target)) return true;
        return false;
    }
};