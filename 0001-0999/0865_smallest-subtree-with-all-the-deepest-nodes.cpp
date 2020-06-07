//Link: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/ 
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
    TreeNode* ans = NULL;
    int depth = 0;
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }
    
    int dfs(TreeNode* root, int d) {
        if(!root) return d;
        int l = dfs(root->left, d + 1);
        int r = dfs(root->right, d + 1);
        if(l >= depth && r >= depth) {
            depth = max(l, r);
            ans = root;
        }
        return max(l, r);
    }
};
