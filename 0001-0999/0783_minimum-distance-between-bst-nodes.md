[783.minimum-distance-between-bst-nodes](https://leetcode.com/problems/minimum-distance-between-bst-nodes/)  

Given a Binary Search Tree (BST) with the root node `root`, return the minimum difference between the values of any two different nodes in the tree.

**Example :**

**Input:** root = \[4,2,6,1,3,null,null\]
**Output:** 1
**Explanation:**
Note that root is a TreeNode object, not an array.

The given tree \[4,2,6,1,3,null,null\] is represented by the following diagram:

          4
        /   \\
      2      6
     / \\    
    1   3  

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.

**Note:**

1.  The size of the BST will be between 2 and `100`.
2.  The BST is always valid, each node's value is an integer, and each node's value is different.
3.  This question is the same as 530: [https://leetcode.com/problems/minimum-absolute-difference-in-bst/](https://leetcode.com/problems/minimum-absolute-difference-in-bst/)  



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
    int minDiffInBST(TreeNode* root) {
        if( root == NULL ) return 0;
        int lval = 1000000;
        int rval = 1000000;
        if( root->left ){
            lval = help(root->val, root->left);
            
            int res = minDiffInBST(root->left);
            if( res <lval && res > 0 )
                lval = res;
        }
        if( root->right ){
            rval = help(root->val, root->right);
            int res = minDiffInBST(root->right);
            if( res < rval && res > 0 )
                rval = res;
        }
        return rval < lval ? rval : lval;
        
    }
    
    int help(int val, TreeNode* root){
        if( val == root->val)
            return 1000000;
        int res = abs(root->val -val);
        if( root->left ){
            int lval = help(val, root->left);
            if( lval < res )
                res = lval;
            
        }
        if( root->right){
            int rval = help(val, root->right);
            if( rval < res)
                res = rval;
        }
        return res;
    }
};
```
      