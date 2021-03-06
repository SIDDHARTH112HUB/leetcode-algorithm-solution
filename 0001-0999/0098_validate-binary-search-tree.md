[98.validate-binary-search-tree](https://leetcode.com/problems/validate-binary-search-tree/)  

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

*   The left subtree of a node contains only nodes with keys **less than** the node's key.
*   The right subtree of a node contains only nodes with keys **greater than** the node's key.
*   Both the left and right subtrees must also be binary search trees.

**Example 1:**

  
    2
  
   / \\
  
  1   3
  

  
**Input:** \[2,1,3\]
  
**Output:** true
  

**Example 2:**

  
    5
  
   / \\
  
  1   4
  
     / \\
  
    3   6
  

  
**Input:** \[5,1,4,null,null,3,6\]
  
**Output:** false
  
**Explanation:** The root node's value is 5 but its right child's value is 4.  



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
    bool isValidBST(TreeNode* root) {
        if( !root ) return true;
        return helper(root, LONG_MIN, LONG_MAX);
    }
    
    bool helper(TreeNode *root, long long min, long long max){
        if( !root ) return true;
        if( root->val <= min || root->val >= max ) return false;
        return helper(root->left, min, root->val ) && helper(root->right, root->val, max);
    }
};
```
      