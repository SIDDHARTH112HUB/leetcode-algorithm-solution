//Link: https://leetcode.com/problems/binary-tree-coloring-game/ 
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
    int xl = 0, xr = 0;
    vector<int> cnt;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        cnt.resize(n+1);
        int total = dfs(root, x);
        int xcnt = 1 + xr + xl;
        if(total - xcnt > xcnt)
            return true;
        if(xr > total - xr)
            return true;
        if(xl > total - xl)
            return true;
        return false;
    }
    
    int dfs(TreeNode* root, int x) {
        if(!root) return 0;
        int l = dfs(root->left, x);
        int r = dfs(root->right, x);
        if(root->val == x){
            xl = l;
            xr = r;
        }
        return l+r+1;
    }
};