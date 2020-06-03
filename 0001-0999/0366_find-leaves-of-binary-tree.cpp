//Link: https://leetcode.com/problems/find-leaves-of-binary-tree/ 
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
    vector<vector<int> > ans;
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int l = dfs(root->left) + 1;
        int r = dfs(root->right) + 1;
        int idx = max(l, r) - 1;
        if(ans.size() <= idx) ans.push_back({});
        ans[idx].push_back(root->val);
        return max(l, r);
    }
};