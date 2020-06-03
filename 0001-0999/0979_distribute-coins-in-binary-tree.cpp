//Link: https://leetcode.com/problems/distribute-coins-in-binary-tree/ 
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
    int distributeCoins1(TreeNode* root) {
        int num = 0;
        solve(NULL, root, num);
        return num;
    }
    int distributeCoins(TreeNode* root) {
        f(root);
        return ans;
    }
    int f(TreeNode* root) {
        if(!root) return 0;
        int l = f(root->left);
        int r = f(root->right);
        root->val += l + r - 1;
        ans += abs(root->val);
        return root->val;
    }
    void solve(TreeNode* parent, TreeNode* root, int &num){
        if( !root ) return;
        
        solve(root, root->left, num);
        solve(root, root->right, num);
        if( !parent ) return ;
        if( root->val == 1 ) return;
        num += abs(root->val-1);
        parent->val += root->val-1;
        return;

    }
};