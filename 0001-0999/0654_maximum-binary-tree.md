[654.maximum-binary-tree](https://leetcode.com/problems/maximum-binary-tree/)  

Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

1.  The root is the maximum number in the array.
2.  The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
3.  The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.

Construct the maximum tree by the given array and output the root node of this tree.

**Example 1:**  

  
**Input:** \[3,2,1,6,0,5\]
  
**Output:** return the tree root node representing the following tree:
  

  
      6
  
    /   \\
  
   3     5
  
    \\    / 
  
     2  0   
  
       \\
  
        1
  

**Note:**  

1.  The size of the given array will be in the range \[1,1000\].  



**Solution:**  

```cpp
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
```
      