//Link: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/ 
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
    int idx = 0;
    
    void setChildNode(string &S, TreeNode* &childNode, int d) {
        int depth = 0;
        int i = idx;
        //find next number depth.
        for (i = idx; i < S.size(); ++i) {
            if (S[i] != '-')
                break;
            ++depth;
        }
        // same depth, the next number is child node.
        if (depth == d) {
            idx = i;
            childNode = recoverFromPreorder(S, d+1);
        }
    }
    TreeNode* recoverFromPreorder(string &S, int d = 1) {
        int sum = 0;
        if (S.size() == 0 ) return NULL;
        for (;idx < S.size(); idx++) {
            if (S[idx] == '-')
                break;
            sum = 10 * sum + S[idx] - '0';
        }
        TreeNode* root = new TreeNode(sum);
        if ( idx == S.size() )
            return root;
        
        setChildNode(S, root->left, d);
        setChildNode(S, root->right, d);
        return root;
    }
};