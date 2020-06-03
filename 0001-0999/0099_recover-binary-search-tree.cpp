//Link: https://leetcode.com/problems/recover-binary-search-tree/ 
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
    void recoverTree(TreeNode* root) {
        vector<int> arr;
        int idx = -1;
        dfs(root, arr, idx);
        sort(arr.begin(), arr.end());
        idx = 0;
        dfs(root, arr, idx);
    }
    void dfs(TreeNode* root, vector<int> &arr, int &idx){
        if( !root )return;
        if( root->left )
            dfs(root->left, arr, idx);
        if( idx == -1 )
            arr.push_back(root->val);
        else{
            root->val = arr[idx++];
        }
        if( root->right )
            dfs(root->right, arr, idx);
    }
};