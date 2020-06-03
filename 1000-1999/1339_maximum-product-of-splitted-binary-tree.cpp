//Link: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/ 
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
    long long sum = 0;
    long long ans = 0;
    long long M = (1e9 + 7);
    int maxProduct(TreeNode* root) {
        s(root);
        h(root);
        return ans % M;
    }
    
    void s(TreeNode* root) {
        if(!root) return;
        sum  += root->val;
        s(root->left);s(root->right);
    }
    long long h(TreeNode* root) {
        if(!root) return 0;
        long long res = h(root->left);
        res += h(root->right);
        res += root->val;
        ans = max(ans, (sum -res ) * res);
        return res;
    }
};