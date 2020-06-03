//Link: https://leetcode.com/problems/find-duplicate-subtrees/ 
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
    unordered_map<string, int> m;
    vector<TreeNode*> ans;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        f(root);
        return ans;
    }
    
    string f(TreeNode* root) {
        if(!root) return "#";
        string res = to_string(root->val) + "," + f(root->left) + "," + f(root->right);
        if(m[res]++ == 1) ans.push_back(root);
        return res;
    }
};