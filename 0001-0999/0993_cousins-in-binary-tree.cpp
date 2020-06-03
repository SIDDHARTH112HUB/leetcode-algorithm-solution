//Link: https://leetcode.com/problems/cousins-in-binary-tree/ 
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
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> a = solve(NULL, root, x, 0);
        vector<int> b = solve(NULL, root, y, 0);
        if( a.size() == 0 || b.size() == 0 ) return false;
        if( a[0] != b[0] && a[1] ==b[1])
            return true;
        return false;
    }
    
    vector<int> solve(TreeNode* p,  TreeNode* root, int x, int h ){
        if( !root ) return {};
        if( root->val == x )
            return {p?p->val : 0, h};
        vector<int> ans ;
        if( root->left && (ans = solve(root, root->left, x, h+1)).size() > 0 )
            return ans;
        if( root->right && (ans = solve( root, root->right, x, h+1)).size() > 0 )
            return ans;
        return ans;
    }
};