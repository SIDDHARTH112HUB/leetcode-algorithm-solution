//Link: https://leetcode.com/problems/closest-binary-search-tree-value/ 
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
    long long closestValue(TreeNode* root, double target) {
        if(!root) return 10000000000;
        double diff = fabs((double)root->val - target);
        long long l = closestValue(root->left, target);
        long long r = closestValue(root->right, target);
        double ldiff = fabs((double)l - target);
        double rdiff = fabs((double)r - target);
        if(diff < ldiff && diff < rdiff) return root->val;
        if(ldiff < diff && ldiff < rdiff) return l;
        return r;
    }
};