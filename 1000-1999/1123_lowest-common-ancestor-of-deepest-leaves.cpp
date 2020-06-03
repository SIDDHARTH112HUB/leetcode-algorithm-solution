//Link: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/ 
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
    vector<TreeNode*> deepest;
    TreeNode* ans;
    int deep = 0;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }
    int dfs(TreeNode *root, int d) {
        if(!root) return 0;
        int l = 1, r =1;
        if(root->left)
            l += dfs(root->left, d+1);
        if(root->right)
            r += dfs(root->right, d+1);
        if(l == r && d + l >= deep){
            ans = root;
            deep = d + l;
        }
        return max(l, r);
    }
};