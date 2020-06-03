//Link: https://leetcode.com/problems/count-univalue-subtrees/ 
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
    int countUnivalSubtrees(TreeNode* root, int p = -1) {
        dfs(root, -1);
        return ans;
    }
    
    
    bool dfs(TreeNode* root, int p) {
        if(!root) return true;
        bool l = dfs(root->left, root->val);
        bool r = dfs(root->right, root->val);
        if(l && r) {
            ++ans;
        }
        return root->val == p && l && r;
    }
};