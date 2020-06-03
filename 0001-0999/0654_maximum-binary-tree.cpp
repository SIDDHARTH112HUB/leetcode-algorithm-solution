//Link: https://leetcode.com/problems/maximum-binary-tree/ 
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums,  TreeNode *root = NULL, int begin=0, int end=1) {
        //return NULL;
        
        if( end < begin ) return NULL;
        if( root == NULL ){
            root = new TreeNode(0);
            begin = 0;
            end = nums.size()-1;
        }
        int max= -1, idx=0;
        for( int i = begin; i<=end; i++){
            if( nums[i] > max ){
                max = nums[i];
                idx = i;
            }
        }
        
        int mid = idx;
        root->val = max;
        //printf("2. %d %d %d \n", begin ,end, mid );
        if( begin < mid ){
            root->left = new TreeNode(0);
            constructMaximumBinaryTree(nums, root->left, begin, mid-1);
        }
        if( end > mid ){
            root->right = new TreeNode(0);
            constructMaximumBinaryTree(nums, root->right, mid+1, end);
        }
        return root;
    }
};