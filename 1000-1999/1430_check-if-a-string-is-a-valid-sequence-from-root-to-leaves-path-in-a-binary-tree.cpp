//Link: https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree/ 
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
    bool dfs(TreeNode* p, TreeNode* root, vector<int>& arr, int idx) {
        if(idx >= arr.size()) return root == NULL && !p->left && !p->right;
        if(!root) return false;
        return root->val == arr[idx] ? (dfs(root, root->left, arr, idx+1) || dfs(root, root->right, arr, idx+1)): false;
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return dfs(root, root, arr, 0);
    }
};