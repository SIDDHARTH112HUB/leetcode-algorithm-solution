//Link: https://leetcode.com/problems/construct-string-from-binary-tree/ 
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
    string tree2str(TreeNode* t) {
        if(!t) return "";
        string str = to_string(t->val);
        string l = tree2str(t->left), r = tree2str(t->right);
        if(l.size() || r.size())
            str += "(" + l + ")";
        if(r.size())
            str += "(" + r + ")";
        return str;
    }
};