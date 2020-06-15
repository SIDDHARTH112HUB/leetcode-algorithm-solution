[110.balanced-binary-tree](https://leetcode.com/problems/balanced-binary-tree/)  

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

> a binary tree in which the left and right subtrees of _every_ node differ in height by no more than 1.

**Example 1:**

Given the following tree `[3,9,20,null,null,15,7]`:

    3
   / \\
  9  20
    /  \\
   15   7

Return true.  
  
**Example 2:**

Given the following tree `[1,2,2,3,3,null,null,4,4]`:

       1
      / \\
     2   2
    / \\
   3   3
  / \\
 4   4

Return false.  



**Solution:**  

```cpp
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
    int Height(TreeNode* node, bool &blance)
    {
        if( node == NULL ) return 0;
        int lh = Height(node->left, blance);
        int rh =  Height(node->right, blance);
        if( abs(lh-rh) >1 ) blance = false;
        return ((lh>rh?lh:rh)+1);
    }
    bool isBalanced(TreeNode *root) {
        if ( root == NULL ) return true;
        bool blance = true;
        int lh = Height(root->left, blance);
        int rh = Height(root->right, blance);
        if( !blance ) return blance;
        return abs(lh-rh)<=1;
    }
};
```
      