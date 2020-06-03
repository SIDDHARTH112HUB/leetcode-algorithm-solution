//Link: https://leetcode.com/problems/maximum-average-subtree/ 
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
    double ans = 0;
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    pair<int, int> dfs(TreeNode *root){
        if(!root) return {0, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int total = root->val + l.first + r.first;
        int count = 1 + l.second + r.second;
        ans = max(ans, double(total*1.0/ count));
        return {total, count};
    }
};