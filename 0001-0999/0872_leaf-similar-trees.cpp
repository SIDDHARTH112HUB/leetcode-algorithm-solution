//Link: https://leetcode.com/problems/leaf-similar-trees/ 
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> s1, s2;
        dfs(root1, s1);
        dfs(root2, s2);
        if( s1.size() != s2.size() ) return false;
        for( int i = 0; i<s1.size(); i++){
            if( s1[i] != s2[i])
                return false;
        }
        return true;
    }
    void dfs(TreeNode* root, vector<int> &s){
        if( !root )
            return;
        if( !root->left && !root->right){
            s.push_back(root->val);
            return;
        }
        dfs(root->left, s);
        dfs(root->right, s);
    }
};