//Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/ 
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
    int idx = 0;
    TreeNode* bstFromPreorder(vector<int>& A, int l = INT_MIN, int r = INT_MAX) {
        if(idx >= A.size()) return NULL;
        if(l > A[idx] || A[idx] > r) return NULL;
        int val = A[idx++];
        TreeNode *node = new TreeNode(val);
        if(idx < A.size())
            node->left = bstFromPreorder(A, l, val);
        if(idx < A.size())
            node->right = bstFromPreorder(A, val, r);
        return node;
    }
};