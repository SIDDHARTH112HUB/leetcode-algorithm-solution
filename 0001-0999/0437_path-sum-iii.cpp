//Link: https://leetcode.com/problems/path-sum-iii/ 
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
    int pathSum(TreeNode* root, int sum, bool f = false) {
        if(!root) return 0;
        if(sum - root->val == 0)
            ++ans;
        pathSum(root->left, sum - root->val, true);
        if(f == false)
            pathSum(root->left, sum, false);
        pathSum(root->right, sum - root->val, true);
        if(f == false)
            pathSum(root->right, sum, false);
        return ans;
    }
    
};