[965.univalued-binary-tree](https://leetcode.com/problems/univalued-binary-tree/)  

A binary tree is _univalued_ if every node in the tree has the same value.

Return `true` if and only if the given tree is univalued.

**Example 1:**

![](https://assets.leetcode.com/uploads/2018/12/28/unival_bst_1.png)

  
**Input:** \[1,1,1,1,1,null,1\]
  
**Output:** true
  

**Example 2:**

![](https://assets.leetcode.com/uploads/2018/12/28/unival_bst_2.png)

  
**Input:** \[2,2,2,5,2\]
  
**Output:** false
  

**Note:**

1.  The number of nodes in the given tree will be in the range `[1, 100]`.
2.  Each node's value will be an integer in the range `[0, 99]`.  



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
    bool isUnivalTree(TreeNode* root) {
        if( !root ) return true;
        if( root->left ){
            if( root->left->val != root->val ) return false;
            if( !isUnivalTree(root->left))return false;
        }
        if( root->right ){
            if( root->right->val != root->val ) return false;
            if( !isUnivalTree(root->right))return false;
        }
        return true;
    }
};
```
      