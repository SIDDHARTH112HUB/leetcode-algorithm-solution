//Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/ 
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if( !root ) return;
        auto next = root->next;
        while( next ){
            if( next->left ){
                next = next->left;
                break;
            }else if(next->right ){
                next = next->right;
                break;
            }
            next = next->next;
        }
        if( root->right ){
            root->right->next = next;
        }
        if( root->left ){
            root->left->next = root->right? root->right:next;
            
        }
        connect(root->right);
        connect(root->left);
    }
};