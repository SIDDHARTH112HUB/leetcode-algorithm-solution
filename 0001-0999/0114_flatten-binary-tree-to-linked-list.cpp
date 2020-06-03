//Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/ 
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
    void flatten(TreeNode* root) {
        if( !root) return;
        queue<TreeNode*> q;
        dfs(root, q);
        q.pop();
        auto *node =root;
        while(!q.empty()){
            node->left  = nullptr;
            node->right = q.front();
            node = node->right;
            q.pop();
        }
        if( node ){
            node->right = nullptr;
            node->left = nullptr;
        }
    }
    void dfs(TreeNode* root, queue<TreeNode*>& q){
        if(!root ) return;
        q.push(root);
        dfs(root->left, q);
        dfs(root->right, q);
    }
};