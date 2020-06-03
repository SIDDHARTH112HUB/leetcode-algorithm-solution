//Link: https://leetcode.com/problems/binary-tree-cameras/ 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

const int NO_CAMERA = 0;
const int HAS_CAMERA= 1;
const int NO_NEEDED = 2;
class Solution {
public:
    int res = 0;
    int minCameraCover(TreeNode* root) {
        if( !root ) return 0;
        return (dfs(root) == NO_CAMERA ? 1:0)+res;
    }
    
    int dfs(TreeNode* root){
        
        //if( !root->left && !root->right) return 0;
        int left = root->left ? dfs(root->left) : NO_NEEDED;
        int right = root->right? dfs(root->right) : NO_NEEDED;
        if( left == NO_CAMERA || right == NO_CAMERA ){
            ++res;
            return HAS_CAMERA;
        }
        return (left==HAS_CAMERA || right ==HAS_CAMERA ) ? NO_NEEDED : NO_CAMERA;
    }
};