//Link: https://leetcode.com/problems/binary-tree-pruning/ 
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
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode* ans = root;
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* &node){
        if(!node) return;
        dfs(node->left);
        dfs(node->right);
        if( node->left == nullptr && node->right == nullptr && node->val == 0 ){
            node = nullptr;
            return ;
        }
    }
};