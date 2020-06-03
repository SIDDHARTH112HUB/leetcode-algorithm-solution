//Link: https://leetcode.com/problems/binary-tree-right-side-view/ 
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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> pq;
        pq.push(root);
        vector<int> ans;
        while( pq.size() ){
            int size = pq.size();
            TreeNode* node = NULL;
            while( size-- > 0 ){
                node = pq.front();
                pq.pop();
                if( node->left )
                    pq.push(node->left);
                if(node->right)
                    pq.push(node->right);
            }
            if( node )
                ans.push_back(node->val);
        }
        return ans;
    }
};