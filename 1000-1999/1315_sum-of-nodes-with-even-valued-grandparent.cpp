//Link: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/ 
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
    int ans = 0;
    int sumEvenGrandparent(TreeNode* root) {
        h(root, -1, -1);
        return ans;
    }
    
    void h(TreeNode* root, int p, int gp) {
        if(!root) return;
        if(gp > 0 && gp % 2 == 0) {
            ans += root->val;
        }
        h(root->left, root->val, p);
        h(root->right, root->val, p);
    }
};