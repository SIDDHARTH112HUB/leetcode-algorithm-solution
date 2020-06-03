//Link: https://leetcode.com/problems/check-completeness-of-a-binary-tree/ 
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
    bool isCompleteTree1(TreeNode* root) {
        if( !root ) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool isLeaveLevel = false;
        while( q.size() ){
            int size = q.size();
            while( size-- > 0 ){
                auto node = q.front();
                q.pop();
                if( isLeaveLevel && (node->left || node->right ) )
                    return false;
                if( !node->left && node->right )
                    return false;
                if( node->left )
                    q.push(node->left);
                if( node->right)
                    q.push(node->right);
                if( !node->left || !node->right )
                    isLeaveLevel = true;
            }
        }
        return true;
    }
    bool isCompleteTree(TreeNode* root) {
        h(root);
        return res;
    }
    bool res = true;
    int h(TreeNode* root) {
        if(!root) return 0;
        int l = h(root->left) + 1;
        int r = h(root->right) + 1;
        if(r > l || l - 1 >r) {
            res = false;
        }
        return max(l, r);
    }
};