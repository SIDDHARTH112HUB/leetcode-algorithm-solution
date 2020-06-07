//Link: https://leetcode.com/problems/find-all-the-lonely-nodes/ 
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
    vector<int> getLonelyNodes(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    void dfs(TreeNode* root) {
        if(!root) return;
        if(!root->left || !root->right) {
            if(!root->left && !root->right) return;
            if(root->left)
                ans.push_back(root->left->val);
            else
                ans.push_back(root->right->val);
        }
        dfs(root->left);
        dfs(root->right);
        return;
    }
};