[669.trim-a-binary-search-tree](https://leetcode.com/problems/trim-a-binary-search-tree/)  

Given a binary search tree and the lowest and highest boundaries as `L` and `R`, trim the tree so that all its elements lies in `[L, R]` (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

**Example 1:**  

  
**Input:** 
  
    1
  
   / \\
  
  0   2
  

  
  L = 1
  
  R = 2
  

  
**Output:** 
  
    1
  
      \\
  
       2
  

**Example 2:**  

  
**Input:** 
  
    3
  
   / \\
  
  0   4
  
   \\
  
    2
  
   /
  
  1
  

  
  L = 1
  
  R = 3
  

  
**Output:** 
  
      3
  
     / 
  
   2   
  
  /
  
 1  



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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        root = trim(root, L, R);
        return root;
    }
    TreeNode* trim(TreeNode* parent, int L, int R ){
        if( !parent )
            return NULL;
        if( parent->val < L ){
            parent->right = trim(parent->right, L, R );
            parent = parent->right;
        }
        else if( parent->val > R ){
            parent->left = trim(parent->left, L, R );
            parent = parent->left;
        }
        else{
            parent->left = trim(parent->left, L, R );
            parent->right = trim(parent->right, L, R );
        }
        return parent;
    }
};
```
      