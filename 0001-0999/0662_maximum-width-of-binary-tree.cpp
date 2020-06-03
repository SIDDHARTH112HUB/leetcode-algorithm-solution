//Link: https://leetcode.com/problems/maximum-width-of-binary-tree/ 
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
    int widthOfBinaryTree(TreeNode* root) {
        if( !root ) return 0;
        queue<pair<TreeNode*, int> > q;
        q.push({root, 1 });
        int ans = 0;
        while(q.size() ){
            int size = q.size();
            ans = max( q.back().second - q.front().second + 1, ans);
            while( size--> 0 ){
                auto node = q.front().first;
                auto idx = q.front().second;
                q.pop();
                if( node->left )
                    q.push({node->left, idx*2});
                if( node->right )
                    q.push({node->right, idx*2+1});
            }
            
        }
        return ans;
    }
};