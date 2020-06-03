//Link: https://leetcode.com/problems/path-sum-ii/ 
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
    vector< vector<int> > ans;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if( !root ) return ans;
        vector<int> item;
        dfs(root, sum, item);
        return ans;
    }
    void dfs(TreeNode* root, int sum, vector<int> &item){
        if( sum == root->val && root->left == nullptr && root->right == nullptr){
            item.push_back(root->val);
            ans.push_back(item);
            item.pop_back();
            return;
        }
        if( !root )
            return;
        item.push_back(root->val);
        if( root->left )
            dfs(root->left, sum-root->val, item);
        if( root->right)
            dfs(root->right, sum-root->val, item);
        item.pop_back();
    }
};