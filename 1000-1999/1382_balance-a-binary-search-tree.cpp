//Link: https://leetcode.com/problems/balance-a-binary-search-tree/ 
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
    vector<int> arr;
    TreeNode* balanceBST(TreeNode* root) {
        d(root);
        sort(arr.begin(), arr.end());
        return h(0, arr.size()-1);
    }
    
    void d(TreeNode* root) {
        if(!root) return;
        arr.push_back(root->val);
        d(root->left);
        d(root->right);
    }
    TreeNode* h(int l, int r) {
        if(l > r) return NULL;
        if(l == r) return new TreeNode(arr[l]);
        int mid = (l + r) / 2;
        auto node = new TreeNode(arr[mid]);
        node->left = h( l, mid - 1);
        node->right = h( mid + 1, r);
        return node;
    }
};