//Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/ 
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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if( !root ) return ans;
        queue<TreeNode* > q;
        stack<TreeNode* > stk;
        q.push(root);
        int d=0;
        vector<int> item;
        while(q.size() ){
            
            TreeNode* node = q.front();
            item.push_back(node->val);
            q.pop();
            if( d % 2 == 1 ){
                if( node->right)
                    stk.push(node->right);
                if( node->left)
                    stk.push(node->left);
            }else{
                if( node->left)
                    stk.push(node->left);
                if( node->right)
                    stk.push(node->right);
            }
            if( q.size() == 0 ){
                ans.push_back(item);
                item = {};
                d++;
                for(;stk.size()>0; stk.pop())
                    q.push(stk.top());
            }
        }
        return ans;
    }
};