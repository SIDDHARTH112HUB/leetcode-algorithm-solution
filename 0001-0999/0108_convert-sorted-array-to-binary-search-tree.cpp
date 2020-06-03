//Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/ 
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
    TreeNode* sortedArrayToBST(vector<int>& nums, TreeNode **node = NULL, int l = -10, int r =-10) {
        if( l == -10 ){
            l = 0;
            r = nums.size()-1;
        }
        TreeNode* root = NULL;
        if( node == NULL )
            node = &root;
        if( l<=r ){
            int mid = (l+r)/2;
            if( *node == NULL ){
                root = new TreeNode(nums[mid]);
                *node = root;
            }
            sortedArrayToBST(nums, &root->left, l, mid-1);
            sortedArrayToBST(nums, &root->right, mid+1,r);
            
            
        }
        return root;
    }
};