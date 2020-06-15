[951.flip-equivalent-binary-trees](https://leetcode.com/problems/flip-equivalent-binary-trees/)  

For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is _flip equivalent_ to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Write a function that determines whether two binary trees are _flip equivalent_.  The trees are given by root nodes `root1` and `root2`.

**Example 1:**

**Input:** root1 = \[1,2,3,4,5,6,null,null,null,7,8\], root2 = \[1,3,2,null,6,4,5,null,null,null,null,8,7\]
**Output:** true
**Explanation:** We flipped at nodes with values 1, 3, and 5.
![Flipped Trees Diagram](https://assets.leetcode.com/uploads/2018/11/29/tree_ex.png)

**Note:**

1.  Each tree will have at most `100` nodes.
2.  Each value in each tree will be a unique integer in the range `[0, 99]`.  



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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if( !root1 && !root2 ) return true;
        if( !root1 || !root2 ) return false;
        if( root1->val != root2->val ) return false;
        if(  flipEquiv( root1->left, root2->left) && flipEquiv( root1->right, root2->right))
            return true;
        if( flipEquiv( root1->left, root2->right) && flipEquiv( root1->right, root2->left) )
            return true;
        return false;
    }
};
```
      