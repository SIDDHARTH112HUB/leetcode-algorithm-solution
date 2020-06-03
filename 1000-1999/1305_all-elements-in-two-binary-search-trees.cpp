//Link: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/ 
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
    vector<int> a;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        h(root1);h(root2);
        sort(a.begin(), a.end());
        return a;
    }
    void h(TreeNode* root) {
        if(!root) return;
        a.push_back(root->val);
        h(root->left);
        h(root->right);
    }
};