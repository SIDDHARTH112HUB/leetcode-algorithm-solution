//Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/ 
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
    int cal(TreeNode* node, int num, int& sum){
        if( node == NULL ) return num;
        int new_num = num*10 + node->val;
        if( node->left == NULL && node->right == NULL ){
            sum = sum + new_num;
            return new_num;
        }
        int r = 0;
        if( node->left != NULL )
            r = cal( node->left, new_num, sum);
        if( node->right != NULL )
            r = cal( node->right, new_num, sum);
        return r;
    }
    int sumNumbers(TreeNode *root) {
        if( root == NULL ) return 0;
        int sum = 0;
        cal( root, 0, sum);
        return sum;
    }
};