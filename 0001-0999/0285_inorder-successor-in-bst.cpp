//Link: https://leetcode.com/problems/inorder-successor-in-bst/ 
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
    bool find = false;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root) return NULL;
        auto l = inorderSuccessor(root->left, p);
        if(l) return l;
        if(find == true) return root;
        find = root == p;
        return inorderSuccessor(root->right, p);
    }
    
};