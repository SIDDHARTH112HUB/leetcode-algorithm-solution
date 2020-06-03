//Link: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/ 
class Solution {
public:
    int ans = 0;
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        h(root->left, 0);
        h(root->right, 1);
        return ans;
    }
    
    int h(TreeNode* root, int d) {
        if(!root) return 0;
        int l = h(root->left, 0) + (d == 1);
        int r = h(root->right, 1) + (d == 0);
        ans = max(ans, max(l , r));
        return d == 0 ? r : l;
    }
};