[108.convert-sorted-array-to-binary-search-tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)  

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of _every_ node never differ by more than 1.

**Example:**

Given the sorted array: \[-10,-3,0,5,9\],

One possible answer is: \[0,-3,9,-10,null,5\], which represents the following height balanced BST:

      0
     / \\
   -3   9
   /   /
 -10  5  



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
```
      