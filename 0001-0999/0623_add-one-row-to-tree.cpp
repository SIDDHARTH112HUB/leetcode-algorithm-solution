//Link: https://leetcode.com/problems/add-one-row-to-tree/ 
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(!root) return NULL;
        if( d == 1){
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }
        if( d == 2) {
            auto l = new TreeNode(v);
            l->left = root->left;
            root->left = l;
            auto r = new TreeNode(v);
            r->right = root->right;
            root->right = r;
            return root;
        }
        addOneRow(root->left, v, d - 1);
        addOneRow(root->right, v, d-1);
        return root;
    }
    
    TreeNode* addOneRow2(TreeNode* root, int v, int d) {
        if(d == 1) {
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            int size = q.size();
            while(size-- > 0){
                auto node = q.front();
                q.pop();
                auto l = node->left;
                if( d == 2) {
                    l = new TreeNode(v);
                    l->left = node->left;
                    node->left = l;
                }
                if(l)
                    q.push(l);

                auto r = node->right;
                if( d== 2){
                    r = new TreeNode(v);
                    r->right = node->right;
                    node->right = r;
                }
                if(r)
                    q.push(r);
                
                
            }
            if(d == 2)
                return root;
            --d;
        }
        return root;
    }
};