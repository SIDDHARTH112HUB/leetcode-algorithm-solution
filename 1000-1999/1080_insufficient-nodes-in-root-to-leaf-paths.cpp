//Link: https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/ 
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
    TreeNode* sufficientSubset(TreeNode* root, long long limit) {
        if(!root) return root;
        return dfs(root, 0, limit) ? NULL : root;
    }
    
    bool dfs(TreeNode* root, long long sum, long long limit) {
        if(!root) return sum < limit;
        if(!root->left && !root->right ) return (root->val + sum) < limit;
        auto left = root->left;
        auto right = root->right;
        bool l = dfs(root->left, sum + root->val, limit);
        if(l) {
            root->left = NULL;
        }
        bool r = dfs(root->right, sum + root->val, limit);
        if(r){
            root->right = NULL;
        }
        return root->left == root->right;
    }
};