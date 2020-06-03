//Link: https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/ 
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
    vector<int> ans;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int idx = 0;
        if( !dfs(root, voyage, idx))
            return {-1};
        return ans;
    }
    
    bool dfs( TreeNode* root, vector<int>& voyage, int &idx){
        if( !root ) return true;
        if( root->val != voyage[idx]) return false;
        if( root->left && root->left->val != voyage[idx+1]){
            if( !root->right || root->right->val != voyage[idx+1] )
                return false;
            ans.push_back(root->val);
            auto tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            
        }
        ++idx;
        if( !dfs(root->left, voyage, idx) )
            return false;
        if( !dfs(root->right, voyage, idx) )
            return false;
        return true;
    }
};