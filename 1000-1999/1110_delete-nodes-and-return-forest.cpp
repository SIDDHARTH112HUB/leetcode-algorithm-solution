//Link: https://leetcode.com/problems/delete-nodes-and-return-forest/ 
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
    vector<TreeNode*> ans;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return {};
        unordered_set<int> s(to_delete.begin(), to_delete.end());
        if(s.count(root->val) == 0)
            ans.push_back(root);
        dfs(root, s);
        return ans;
    }
    
    void dfs(TreeNode* &root, unordered_set<int> &s) {
        if(!root) return;
        auto &l = root->left;
        auto &r = root->right;
        if(s.count(root->val)) {
            if(l && s.count(l->val) == 0)
                ans.push_back(l);
            if(r && s.count(r->val) == 0)
                ans.push_back(r);
            root = NULL;
        }
        dfs(l, s);
        dfs(r, s);
    }
};