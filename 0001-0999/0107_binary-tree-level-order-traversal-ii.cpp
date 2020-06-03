//Link: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/ 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        
        vector< vector< int > > data;
        if( root == NULL ) return data;
        vector< TreeNode* > nodes;
        nodes.push_back( root );
        int idx = 0, size = nodes.size();
        
        while( idx < size )
        {
            vector< int > row;
            for( ; idx<size; idx++)
            {
                TreeNode* node = nodes[idx];
                row.push_back( node->val);
                if( node->left != NULL ) nodes.push_back( node->left);
                if( node->right != NULL ) nodes.push_back( node->right);
            }
            data.push_back( row );
            //row.clear();
            size = nodes.size();
            
        }
        std::reverse( data.begin(), data.end());
        return data;
    }
};