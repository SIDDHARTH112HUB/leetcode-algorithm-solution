//Link: https://leetcode.com/problems/largest-bst-subtree/ 
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
    int ans = 0;
    int largestBSTSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    vector<int> dfs(TreeNode* root) {
        if(!root) return {INT_MAX, INT_MIN, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        if(l[1] < root->val && r[0] > root->val) {
            ans = max(ans, l[2] + r[2] + 1);
            return { min(l[0], root->val), max(r[1],root->val), l[2] + r[2] + 1 };
        }else
            return {INT_MIN, INT_MAX, 0};
    }
};