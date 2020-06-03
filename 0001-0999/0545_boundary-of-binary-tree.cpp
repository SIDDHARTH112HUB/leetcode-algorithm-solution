//Link: https://leetcode.com/problems/boundary-of-binary-tree/ 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return ans;
        ans.push_back(root->val);
        dfs(root->left, true, false);
        dfs(root->right, false, true);
        return ans;
    }
    
    void dfs(TreeNode* root, bool leftMost, bool rightMost) {
        if(!root) return;
        if(!root->left && !root->right) {
            ans.push_back(root->val);
            return;
        }
        if(leftMost)
            ans.push_back(root->val);
        dfs(root->left, leftMost, rightMost && !root->right);
        dfs(root->right, leftMost && !root->left, rightMost);
        if(rightMost)
            ans.push_back(root->val);
    }
};