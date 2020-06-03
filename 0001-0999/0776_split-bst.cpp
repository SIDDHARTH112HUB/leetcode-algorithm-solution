//Link: https://leetcode.com/problems/split-bst/ 
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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if(!root) return {NULL, NULL};
        if(root->val > V) {
            auto res = splitBST(root->left, V);
            root->left = res[1];
            res[1] = root;
            return res;
        }else {
            auto res = splitBST(root->right, V);
            root->right = res[0];
            res[0] = root;
            return res;
        }
        return {NULL, NULL};
    }
};