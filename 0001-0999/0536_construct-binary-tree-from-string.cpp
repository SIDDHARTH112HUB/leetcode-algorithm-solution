//Link: https://leetcode.com/problems/construct-binary-tree-from-string/ 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* str2tree(string s) {
        if(s == "") return NULL;
        int idx = 0;
        return dfs(s, idx);
    }
    
    TreeNode* dfs(string &s, int &idx) {
        if(idx >= s.size()) return NULL;
        int sign = 1;
        if(s[idx] == '-') {
            sign = -1;
            ++idx;
        }
        int sum = 0;
        while(s[idx] <= '9' && s[idx] >= '0') {
            sum = sum * 10 + s[idx] - '0';
            ++idx;
        }
        TreeNode* node = new TreeNode(sum * sign);
        if(idx >= s.size()) return node;
        if(s[idx] == ')') {
            ++idx;
            return node;
        }
        ++idx;
        node->left = dfs(s, idx);
        if(idx >= s.size()) return node;
        if(idx < s.size() && s[idx] == ')') {
            ++idx;
            return node;
        }
        ++idx;
        node->right = dfs(s, idx);
        ++idx;
        return node;
    }
};