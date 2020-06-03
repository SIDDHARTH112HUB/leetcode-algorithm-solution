//Link: https://leetcode.com/problems/find-mode-in-binary-search-tree/ 
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
    map<int, int> data;
    int max_num = 0;
    vector<int> findMode(TreeNode* root) {
        solve(root);
        vector<int> ans;
        for(auto &it:data){
            if( it.second == max_num )
                ans.push_back(it.first);
        }
        return ans;
    }
    void solve(TreeNode* root){
        if(!root) return;
        solve(root->left);
        solve(root->right);
        data[root->val]++;
        if( data[root->val] > max_num )
            max_num = data[root->val];
    }
};